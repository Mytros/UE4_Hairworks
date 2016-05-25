// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using System.Xml.Serialization;
using System.Collections;
using System.Collections.Generic;
using Tools.DotNETCommon.XmlHandler;
using System.Xml;
using System.Linq;
using System.Security;
using System.Diagnostics;

namespace Tools.CrashReporter.CrashReportCommon
{
	/*
	 Unused Crashes' fields.
	 
			Title				nchar(20)		
			Selected			bit				
			Version				int				
			AutoReporterID		int				
			Processed			bit				
			HasDiagnosticsFile	bit				
			HasNewLogFile		bit				
			HasMetaData			bit				

	 Fields of Crashes used only by the crash report website. 
		
			Status				varchar(64)			- Status of the crash.
			Pattern				varchar(800)		- Pattern used to group cashes into buggs.
			FixedChangeList		varchar(64)			- Changelist that fixed this crash.
			Module				varchar(128)		- Name of the module where the crash occurred.
			UserNameId			int					- The ID of the user name.
			Jira				varchar(64)			- The Jira.
			CrashType			smallint NOT NULL	- The type of the crash, crash(1), assert(2), ensure(3)
	*/

	/* PrimaryCrashProperties. Extracted from: FGenericCrashContext::SerializeContentToBuffer */
	/*
		"CrashVersion"
		"ProcessId"
		"CrashGUID"
		"IsInternalBuild"
		"IsPerforceBuild"
		"IsSourceDistribution"
		"SecondsSinceStart"
		"GameName"
		"ExecutableName"
		"BuildConfiguration"
		"PlatformName"
		"PlatformNameIni"
		"PlatformFullName"
		"EngineMode"
		"EngineVersion"
		"CommandLine"
		"LanguageLCID"
		"AppDefaultLocale"
		"IsUE4Release"
		"UserName"
		"BaseDir"
		"RootDir"
		"MachineId"
		"EpicAccountId"
		"CallStack"
		"SourceContext"
		"UserDescription"
		"ErrorMessage"
		"CrashDumpMode"
		"Misc.NumberOfCores"
		"Misc.NumberOfCoresIncludingHyperthreads"
		"Misc.Is64bitOperatingSystem"
		"Misc.CPUVendor"
		"Misc.CPUBrand"
		"Misc.PrimaryGPUBrand"
		"Misc.OSVersionMajor"
		"Misc.OSVersionMinor"
		"Misc.AppDiskTotalNumberOfBytes"
		"Misc.AppDiskNumberOfFreeBytes"
		"MemoryStats.TotalPhysical"
		"MemoryStats.TotalVirtual"
		"MemoryStats.PageSize"
		"MemoryStats.TotalPhysicalGB"
		"MemoryStats.AvailablePhysical"
		"MemoryStats.AvailableVirtual"
		"MemoryStats.UsedPhysical"
		"MemoryStats.PeakUsedPhysical"
		"MemoryStats.UsedVirtual"
		"MemoryStats.PeakUsedVirtual"
		"MemoryStats.bIsOOM"
		"MemoryStats.OOMAllocationSize"
		"MemoryStats.OOMAllocationAlignment"
		"TimeofCrash"
		"bAllowToBeContacted"
	*/

	/// <summary> Enumerates crash description versions. </summary>
	public enum ECrashDescVersions
	{
		/// <summary> Introduces a new crash description format. </summary>
		VER_1_NewCrashFormat,

		/// <summary> Added misc properties (CPU,GPU,OS,etc), memory related stats and platform specific properties as generic payload. </summary>
		VER_2_AddedNewProperties,

		/// <summary> Using crash context when available. </summary>
		VER_3_CrashContext = 3,
	}

	/// <summary> 
	/// GenericCrashContext for managed code. Based on XML file.
	/// Holds data from the CrashContext.runtime-xml file
	/// Must match FGenericCrashContext::SerializeContentToBuffer
	/// 
	/// 1. Generated by FGenericCrashContext::SerializeContentToBuffer via the native code
	/// 2. Updated with callstack, source context etc via the crash report client / crash report process
	/// 3. Read by the crash report process, verified and forward in the same form to the crash report frontend
	/// 4. Basic properties displayed directly in the frontend (already existing in the database), remaining properties are displayed per crash read from the CrashContext.runtime-xml file.
	/// 
	/// <RuntimeCrashDescription></RuntimeCrashDescription>
	/// <version></version>
	/// <PlatformSpecificProperties>
	/// 
	/// </PlatformSpecificProperties>
	/// </summary>
	public class FGenericCrashContext
	{
		/// <summary> Name of the crash context file. </summary>
		public const string CrashContextRuntimeXMLName = "CrashContext.runtime-xml";

		/// <summary>Required properties</summary>
		[XmlElement( ElementName = "RuntimeProperties" )]
		public FPrimaryCrashProperties PrimaryCrashProperties = new FPrimaryCrashProperties();

		/// <summary>Optional, platform specific properties</summary>
		[XmlElement( ElementName = "PlatformProperties" )]
		public object UntypedXMLNodes;

		/// <summary> Directory of the crash. </summary>
		public string CrashDirectory;

		//// <summary> Platform specific properties. </summary>
		//[XmlElement]
		//public List<KeyValuePair<string, string>> PlatformProperties = new List<KeyValuePair<string, string>>();

		/// <summary>A simple default constructor to allow Xml serialization.</summary>
		public FGenericCrashContext()
		{
		}

		/// <summary> Creates a new instance of the crash report context from the specified file. </summary>
		public static FGenericCrashContext FromFile( string Filepath )
		{
			// The crash report context contains invalid characters, we need to fix them all in order to parse the XML.
			HashSet<string> TagsToIgnore = new HashSet<string>() { "<FGenericCrashContext>", "<RuntimeProperties>", "<PlatformProperties>", "</FGenericCrashContext>", "</RuntimeProperties>", "</PlatformProperties>" };

			string[] XMLText = File.ReadAllLines( Filepath );
			string CopyText = string.Join( Environment.NewLine, XMLText );

			string NodeOpen = "";
			string NodeEnd = "";

			List<string> Multiline = new List<string>();
			List<int> MultiIndex = new List<int>();

			int OpenEnd = 0;
			int EndStart = 0;
			for (int LineIndex = 1; LineIndex < XMLText.Length; LineIndex++)
			{
				string XMLLine = XMLText[LineIndex].Replace( "\t", "" );
				bool bIgnore = TagsToIgnore.Contains( XMLLine );
				if (bIgnore)
				{
					continue;
				}

				// XML node without data, skip.
				if (XMLLine.Contains( "/>" ))
				{
					continue;
				}

				if (NodeOpen == "")
				{
					// Parse the tag.
					//<Version>"1"</Version>
					//<Version />
					int OpenStart = XMLLine.IndexOf( '<' );
					OpenEnd = XMLLine.IndexOf( '>', OpenStart );
					NodeOpen = XMLLine.Substring( OpenStart + 1, OpenEnd - OpenStart - 1 );
				}

				EndStart = XMLLine.IndexOf( "</" );
				int EndEnd = 0;
				if (EndStart != -1)
				{
					EndEnd = XMLLine.IndexOf( '>', EndStart );
					NodeEnd = XMLLine.Substring( EndStart + 2, EndEnd - EndStart - 2 );
				}
				else
				{
					Multiline.Add( XMLLine.Substring( OpenEnd != 0 ? OpenEnd + 1 : 0 ) );
					MultiIndex.Add( LineIndex );
					OpenEnd = 0;
				}

				// Valid tag, fix invalid characters.
				if (NodeOpen == NodeEnd)
				{
					if (Multiline.Count == 0)
					{
						string NodeValue = XMLLine.Substring( OpenEnd + 1, EndStart - OpenEnd - 1 );
						string EscapedXMLText = EscapeXMLString( UnescapeXMLString( NodeValue ) ); // Required for support old and new type format.
						XMLText[LineIndex] = string.Format( "<{0}>{1}</{0}>", NodeOpen, EscapedXMLText );
					}
					else
					{
						Multiline.Add( XMLLine.Substring( 0, EndStart ) );
						MultiIndex.Add( LineIndex );

						for (int Inner = 0; Inner < Multiline.Count; Inner++)
						{
							string EscapedXMLText = EscapeXMLString( UnescapeXMLString( Multiline[Inner] ) );

							if (Inner == 0)
							{
								XMLText[MultiIndex[Inner]] = string.Format( "<{0}>{1}", NodeOpen, EscapedXMLText );
							}
							else if (Inner == Multiline.Count - 1)
							{
								XMLText[MultiIndex[Inner]] = string.Format( "{1}</{0}>", NodeOpen, EscapedXMLText );
							}
							else
							{
								XMLText[MultiIndex[Inner]] = EscapedXMLText;
							}
						}

						Multiline.Clear();
						MultiIndex.Clear();
					}

					NodeOpen = NodeEnd = "";
				}
			}

			string XMLTextJoined = string.Join( Environment.NewLine, XMLText );
			FGenericCrashContext Context = XmlHandler.FromXmlString<FGenericCrashContext>( XMLTextJoined );

			if (Context.UntypedXMLNodes != null)
			{
				var Typed = ( (IEnumerable)Context.UntypedXMLNodes )
								.Cast<XmlNode>()
								.Select( X => new KeyValuePair<string, string>( X.Name, X.InnerText ) )
								.ToList();
			}

			return Context;
		}

		const string NewLineTag = "&nl;";

		/// <summary> Escape XML string. </summary>
		static public string EscapeXMLString( string Text )
		{
			return Text
				.Replace( "&", "&amp;" )
				.Replace( "\"", "&quot;" )
				.Replace( "'", "&apos;" )
				.Replace( "<", "&lt;" )
				.Replace( ">", "&gt;" )
				// Ignore return carriage.
				.Replace( "\r", "" );
				//.Replace( "\n", NewLineTag );
		}

		/// <summary> Unescape XML string. </summary>
		static public string UnescapeXMLString( string Text )
		{
			return Text
				.Replace( "&amp;", "&" )
				.Replace( "&quot;", "\"" )
				.Replace( "&apos;", "'" )
				.Replace( "&lt;", "<" )
				.Replace( "&gt;", ">" )
				.Replace( NewLineTag, "\n" );
		}

		/// <summary> Whether this crash contains callstack, error message and source context thus it means that crash is complete. </summary>
		public bool HasProcessedData()
		{
			return !string.IsNullOrEmpty(PrimaryCrashProperties.CallStack) &&
					!string.IsNullOrEmpty(PrimaryCrashProperties.ErrorMessage);
		}

		/// <summary> Writes this instance of the crash report context to the specified file. </summary>
		public void ToFile()
		{
			XmlHandler.WriteXml<FGenericCrashContext>( this, Path.Combine( CrashDirectory, FGenericCrashContext.CrashContextRuntimeXMLName ) );
		}

		/// <returns>Unique name of this report, can be used as name of file.</returns>
		public string GetAsFilename()
		{
			string EngineVersion = PrimaryCrashProperties.EngineVersion;

			string Directory = string.Format( "{0}_{1}__{2}", EngineVersion, !string.IsNullOrEmpty( PrimaryCrashProperties.GameName ) ? PrimaryCrashProperties.GameName : "NO_GAMENAME", PrimaryCrashProperties.TimeofCrash.Ticks );
			return Directory;
		}
	}

	/*	
		"EngineVersion"
	 */

	/// <summary> Required properties for the generic crash context. </summary>
	public class FPrimaryCrashProperties
	{
		/// <summary></summary>
		[XmlElement]
		public int CrashVersion;

		/// <summary></summary>
		[XmlElement]
		public string CrashGUID;

		/// <summary></summary>
		[XmlElement]
		public int ProcessId;

		/// <summary></summary>
		[XmlElement]
		public bool IsInternalBuild;

		/// <summary></summary>
		[XmlElement]
		public bool IsPerforceBuild;

		/// <summary></summary>
		[XmlElement]
		public bool IsSourceDistribution;

		/// <summary></summary>
		[XmlElement]
		public int SecondsSinceStart;

		/// <summary></summary>
		[XmlElement]
		public string GameName;

		/// <summary></summary>
		[XmlElement]
		public string ExecutableName;

		/// <summary></summary>
		[XmlElement]
		public string BuildConfiguration;

		/// <summary></summary>
		[XmlElement]
		public string PlatformName;

		/// <summary></summary>
		[XmlElement]
		public string PlatformNameIni;

		/// <summary></summary>
		[XmlElement]
		public string PlatformFullName;

		/// <summary> 
		/// Creates a full platform name, if missing. PlatformName [OS.Major Os.Minor Arch]
		/// Must match 
		/// ...\Engine\Source\Programs\CrashReporter\CrashReportClient\Private\CrashDescription.cpp FCrashContext.FCrashContext 
		///</summary>
		public void SetPlatformFullName()
		{
			if (string.IsNullOrEmpty( PlatformFullName ))
			{
				// Create a new one.
				string LocalPlatformName = "";
				if (BaseDir != "")
				{
					string[] FolderComponents = BaseDir.Split( new[] { '/' }, StringSplitOptions.RemoveEmptyEntries );
					if (FolderComponents.Length != 0)
					{
						LocalPlatformName = FolderComponents[FolderComponents.Length - 1];
					}
				}
				else
				{
					LocalPlatformName = PlatformNameIni;
				}

				if (!string.IsNullOrEmpty( Misc_OSVersionMajor ))
				{
					PlatformFullName = string.Format( "{0} [{1} {2} {3}]", 
						LocalPlatformName,
						Misc_OSVersionMajor,
						string.IsNullOrEmpty( Misc_OSVersionMinor ) ? "" : Misc_OSVersionMinor,
						Misc_Is64bitOperatingSystem ? "64b" : "32b" );
				}
			}
		}

		/// <summary></summary>
		[XmlElement]
		public string EngineMode;

		/// <summary></summary>
		[XmlElement]
		public string EngineVersion;

		/// <summary></summary>
		[XmlElement]
		public string CommandLine;

		/// <summary></summary>
		[XmlElement]
		public int LanguageLCID;

		/// <summary></summary>
		[XmlElement]
		public string AppDefaultLocale;

		/// <summary></summary>
		[XmlElement]
		public bool IsUE4Release;

		/// <summary></summary>
		[XmlElement]
		public string UserName;

		/// <summary></summary>
		[XmlElement]
		public string BaseDir;

		/// <summary></summary>
		[XmlElement]
		public string RootDir;

		/// <summary></summary>
		[XmlElement]
		public string MachineId;

		/// <summary></summary>
		[XmlElement]
		public string EpicAccountId;

		/// <summary></summary>
		[XmlElement]
		public string CallStack;

		/// <summary> Callstack as string[] unescaped. </summary>
		public string[] GetCallstack()
		{
			string UnescapedValue = FGenericCrashContext.UnescapeXMLString( CallStack );
			return UnescapedValue.Split( new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries );
		}

		/// <summary></summary>
		[XmlElement]
		public string SourceContext;

		/// <summary> SourceContext as string[] unescaped. </summary>
		public string[] GetSourceContext()
		{
			string UnescapedValue = FGenericCrashContext.UnescapeXMLString( SourceContext );
			return UnescapedValue.Split( new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries );
		}

		/// <summary> An array of module's name used by the game that crashed. </summary>
		[XmlElement]
		public string Modules;

		/// <summary></summary>
		[XmlElement]
		public string UserDescription;

		/// <summary> UserDescription as string[] unescaped. </summary>
		public string[] GetUserDescription()
		{
			string UnescapedValue = FGenericCrashContext.UnescapeXMLString( UserDescription );
			return UnescapedValue.Split( new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries );
		}

		/// <summary></summary>
		[XmlElement]
		public string ErrorMessage;

		/// <summary> ErrorMessage as string[] unescaped. </summary>
		public string[] GetErrorMessage()
		{
			string UnescapedValue = FGenericCrashContext.UnescapeXMLString( ErrorMessage );
			UnescapedValue = UnescapedValue.Substring( 0, Math.Min( 511, UnescapedValue.Length ) ); // Database limitation.
			return UnescapedValue.Split( new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries );
		}

		/// <summary> Location of the full crash dump. Displayed in the crash report frontend, without the filename. </summary>
		[XmlElement]
		public string FullCrashDumpLocation;

		/// <summary> Fullname of the full crash dump.</summary>
		public string GetFullCrashDumpLocation()
		{
			string Fullname = Path.Combine( FullCrashDumpLocation, CrashReporterConstants.UE4MinidumpName );
			return Fullname;
		}

		/// <summary></summary>
		[XmlElement]
		public int CrashDumpMode;

		

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.NumberOfCores" )]
		public int Misc_NumberOfCores;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.NumberOfCoresIncludingHyperthreads" )]
		public int Misc_NumberOfCoresIncludingHyperthreads;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.Is64bitOperatingSystem" )]
		public bool Misc_Is64bitOperatingSystem;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.CPUVendor" )]
		public string Misc_CPUVendor;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.CPUBrand" )]
		public string Misc_CPUBrand;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.PrimaryGPUBrand" )]
		public string Misc_PrimaryGPUBrand;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.OSVersionMajor" )]
		public string Misc_OSVersionMajor;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.OSVersionMinor" )]
		public string Misc_OSVersionMinor;

		
		/// <summary></summary>
		[XmlElement( ElementName = "Misc.AppDiskTotalNumberOfBytes")]
		public string Misc_AppDiskTotalNumberOfBytes;

		/// <summary></summary>
		[XmlElement( ElementName = "Misc.AppDiskNumberOfFreeBytes")]
		public string Misc_AppDiskNumberOfFreeBytes;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.TotalPhysical")]
		public string MemoryStats_TotalPhysical;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.TotalVirtual")]
		public string MemoryStats_TotalVirtual;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.PageSize")]
		public string MemoryStats_PageSize;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.TotalPhysicalGB")]
		public string MemoryStats_TotalPhysicalGB;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.AvailablePhysical")]
		public string MemoryStats_AvailablePhysical;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.AvailableVirtual")]
		public string MemoryStats_AvailableVirtual;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.UsedPhysical")]
		public string MemoryStats_UsedPhysical;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.PeakUsedPhysical")]
		public string MemoryStats_PeakUsedPhysical;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.UsedVirtual")]
		public string MemoryStats_UsedVirtual;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.PeakUsedVirtual")]
		public string MemoryStats_PeakUsedVirtual;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.bIsOOM")]
		public string MemoryStats_bIsOOM;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.OOMAllocationSize")]
		public string MemoryStats_OOMAllocationSize;

		/// <summary></summary>
		[XmlElement( ElementName = "MemoryStats.OOMAllocationAlignment")]
		public string MemoryStats_OOMAllocationAlignment;


		/// <summary>The UTC time the crash occurred.</summary>
		[XmlElement]
		public DateTime TimeofCrash;

		/// <summary> Whether the user allowed us to be contacted. </summary>
		[XmlElement]
		public bool bAllowToBeContacted = false;

		/// <summary>A simple default constructor to allow Xml serialization.</summary>
		public FPrimaryCrashProperties()
		{ }
	}
}