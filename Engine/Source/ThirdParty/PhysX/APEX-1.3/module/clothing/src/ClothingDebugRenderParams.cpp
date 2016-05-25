/*
 * Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */


// This file was generated by NxParameterized/scripts/GenParameterized.pl
// Created: 2015.06.02 04:11:48

#include "ClothingDebugRenderParams.h"
#include <string.h>
#include <stdlib.h>

using namespace NxParameterized;

namespace physx
{
namespace apex
{
namespace clothing
{

using namespace ClothingDebugRenderParamsNS;

const char* const ClothingDebugRenderParamsFactory::vptr =
    NxParameterized::getVptr<ClothingDebugRenderParams, ClothingDebugRenderParams::ClassAlignment>();

const physx::PxU32 NumParamDefs = 42;
static NxParameterized::DefinitionImpl* ParamDefTable; // now allocated in buildTree [NumParamDefs];


static const size_t ParamLookupChildrenTable[] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23,
	24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
};

#define TENUM(type) physx::##type
#define CHILDREN(index) &ParamLookupChildrenTable[index]
static const NxParameterized::ParamLookupNode ParamLookupTable[NumParamDefs] =
{
	{ TYPE_STRUCT, false, 0, CHILDREN(0), 41 },
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->Actors), NULL, 0 }, // Actors
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->SkinnedPositions), NULL, 0 }, // SkinnedPositions
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->Backstop), NULL, 0 }, // Backstop
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->BackstopPrecise), NULL, 0 }, // BackstopPrecise
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->MaxDistance), NULL, 0 }, // MaxDistance
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->MaxDistanceInwards), NULL, 0 }, // MaxDistanceInwards
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SkinMapAll), NULL, 0 }, // SkinMapAll
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SkinMapBad), NULL, 0 }, // SkinMapBad
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SkinMapActual), NULL, 0 }, // SkinMapActual
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SkinMapInvalidBary), NULL, 0 }, // SkinMapInvalidBary
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->PhysicsMeshWire), NULL, 0 }, // PhysicsMeshWire
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->PhysicsMeshSolid), NULL, 0 }, // PhysicsMeshSolid
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->PhysicsMeshNormals), NULL, 0 }, // PhysicsMeshNormals
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->Skeleton), NULL, 0 }, // Skeleton
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->BoneFrames), NULL, 0 }, // BoneFrames
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->BoneNames), NULL, 0 }, // BoneNames
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->Velocities), NULL, 0 }, // Velocities
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->Wind), NULL, 0 }, // Wind
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->GraphicalVertexBones), NULL, 0 }, // GraphicalVertexBones
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->PhysicalVertexBones), NULL, 0 }, // PhysicalVertexBones
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->CollisionShapes), NULL, 0 }, // CollisionShapes
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->CollisionShapesWire), NULL, 0 }, // CollisionShapesWire
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->LengthFibers), NULL, 0 }, // LengthFibers
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->CrossSectionFibers), NULL, 0 }, // CrossSectionFibers
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->BendingFibers), NULL, 0 }, // BendingFibers
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->ShearingFibers), NULL, 0 }, // ShearingFibers
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->ZerostretchFibers), NULL, 0 }, // ZerostretchFibers
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->TethersActive), NULL, 0 }, // TethersActive
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->TethersInactive), NULL, 0 }, // TethersInactive
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->VirtualCollision), NULL, 0 }, // VirtualCollision
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->FiberRange), NULL, 0 }, // FiberRange
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->ShowInLocalSpace), NULL, 0 }, // ShowInLocalSpace
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->GlobalPose), NULL, 0 }, // GlobalPose
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->RecomputeSubmeshes), NULL, 0 }, // RecomputeSubmeshes
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->RecomputeVertices), NULL, 0 }, // RecomputeVertices
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->PhysicsMeshIndices), NULL, 0 }, // PhysicsMeshIndices
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->MassScale), NULL, 0 }, // MassScale
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SelfCollision), NULL, 0 }, // SelfCollision
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SelfCollisionWire), NULL, 0 }, // SelfCollisionWire
	{ TYPE_F32, false, (size_t)(&((ParametersStruct*)0)->SelfCollisionAttenuation), NULL, 0 }, // SelfCollisionAttenuation
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->SolverMode), NULL, 0 }, // SolverMode
};


bool ClothingDebugRenderParams::mBuiltFlag = false;
NxParameterized::MutexType ClothingDebugRenderParams::mBuiltFlagMutex;

ClothingDebugRenderParams::ClothingDebugRenderParams(NxParameterized::Traits* traits, void* buf, PxI32* refCount) :
	NxParameters(traits, buf, refCount)
{
	//mParameterizedTraits->registerFactory(className(), &ClothingDebugRenderParamsFactoryInst);

	if (!buf) //Do not init data if it is inplace-deserialized
	{
		initDynamicArrays();
		initStrings();
		initReferences();
		initDefaults();
	}
}

ClothingDebugRenderParams::~ClothingDebugRenderParams()
{
	freeStrings();
	freeReferences();
	freeDynamicArrays();
}

void ClothingDebugRenderParams::destroy()
{
	// We cache these fields here to avoid overwrite in destructor
	bool doDeallocateSelf = mDoDeallocateSelf;
	NxParameterized::Traits* traits = mParameterizedTraits;
	physx::PxI32* refCount = mRefCount;
	void* buf = mBuffer;

	this->~ClothingDebugRenderParams();

	NxParameters::destroy(this, traits, doDeallocateSelf, refCount, buf);
}

const NxParameterized::DefinitionImpl* ClothingDebugRenderParams::getParameterDefinitionTree(void)
{
	if (!mBuiltFlag) // Double-checked lock
	{
		NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

const NxParameterized::DefinitionImpl* ClothingDebugRenderParams::getParameterDefinitionTree(void) const
{
	ClothingDebugRenderParams* tmpParam = const_cast<ClothingDebugRenderParams*>(this);

	if (!mBuiltFlag) // Double-checked lock
	{
		NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			tmpParam->buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

NxParameterized::ErrorType ClothingDebugRenderParams::getParameterHandle(const char* long_name, Handle& handle) const
{
	ErrorType Ret = NxParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

NxParameterized::ErrorType ClothingDebugRenderParams::getParameterHandle(const char* long_name, Handle& handle)
{
	ErrorType Ret = NxParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

void ClothingDebugRenderParams::getVarPtr(const Handle& handle, void*& ptr, size_t& offset) const
{
	ptr = getVarPtrHelper(&ParamLookupTable[0], const_cast<ClothingDebugRenderParams::ParametersStruct*>(&parameters()), handle, offset);
}


/* Dynamic Handle Indices */

void ClothingDebugRenderParams::freeParameterDefinitionTable(NxParameterized::Traits* traits)
{
	if (!traits)
	{
		return;
	}

	if (!mBuiltFlag) // Double-checked lock
	{
		return;
	}

	NxParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);

	if (!mBuiltFlag)
	{
		return;
	}

	for (physx::PxU32 i = 0; i < NumParamDefs; ++i)
	{
		ParamDefTable[i].~DefinitionImpl();
	}

	traits->free(ParamDefTable);

	mBuiltFlag = false;
}

#define PDEF_PTR(index) (&ParamDefTable[index])

void ClothingDebugRenderParams::buildTree(void)
{

	physx::PxU32 allocSize = sizeof(NxParameterized::DefinitionImpl) * NumParamDefs;
	ParamDefTable = (NxParameterized::DefinitionImpl*)(mParameterizedTraits->alloc(allocSize));
	memset(static_cast<void*>(ParamDefTable), 0, allocSize);

	for (physx::PxU32 i = 0; i < NumParamDefs; ++i)
	{
		NX_PARAM_PLACEMENT_NEW(ParamDefTable + i, NxParameterized::DefinitionImpl)(*mParameterizedTraits);
	}

	// Initialize DefinitionImpl node: nodeIndex=0, longName=""
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[0];
		ParamDef->init("", TYPE_STRUCT, "STRUCT", true);






	}

	// Initialize DefinitionImpl node: nodeIndex=1, longName="Actors"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[1];
		ParamDef->init("Actors", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Enables/Disables visualization of all clothing actors", true);
		ParamDefTable[1].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=2, longName="SkinnedPositions"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[2];
		ParamDef->init("SkinnedPositions", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Marks each animation position with a small cross as the centers of the spheres in which the simulated vertices are allowed to move. Blue for static vertices, black to white for increasing max distance.", true);
		ParamDefTable[2].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=3, longName="Backstop"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[3];
		ParamDef->init("Backstop", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "The part of the mesh with backstop is solidly rendered. Red for front faces, blue for back faces.", true);
		ParamDefTable[3].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=4, longName="BackstopPrecise"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[4];
		ParamDef->init("BackstopPrecise", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws small segments of the backstop sphere for each simulation vertex. (scalable)", true);
		ParamDefTable[4].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=5, longName="MaxDistance"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[5];
		ParamDef->init("MaxDistance", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws a line from the skinned position along the skinned normal with the length of the max distance this vertex is allowed to move.  Note that the LoD mechanism can scale down the Max Distance of the asset.", true);
		ParamDefTable[5].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=6, longName="MaxDistanceInwards"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[6];
		ParamDef->init("MaxDistanceInwards", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Same as MaxDistance but to the other side. Bounded by backstop.  The length of the line is either Max Distance or sphere collision distance, depending on which is smaller and restricts the motion of the vertex.", true);
		ParamDefTable[6].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=7, longName="SkinMapAll"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[7];
		ParamDef->init("SkinMapAll", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws the full support mesh for mesh-mesh skinning.", true);
		ParamDefTable[7].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=8, longName="SkinMapBad"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[8];
		ParamDef->init("SkinMapBad", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws the support mesh for mesh-mesh skinning. But only for vertices that actually lie outside of the support mesh and could cause problems", true);
		ParamDefTable[8].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=9, longName="SkinMapActual"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[9];
		ParamDef->init("SkinMapActual", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws the actual support mesh for mesh-mesh skinning (only the parts that are effectively used).", true);
		ParamDefTable[9].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=10, longName="SkinMapInvalidBary"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[10];
		ParamDef->init("SkinMapInvalidBary", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws physical triangles and corresponding graphical vertices that have invalid barycentric coordinates in the mesh skinning map. Red: invalid position bary. Purple: invalid normal bary. Blue: invalid tangent bary.", true);
		ParamDefTable[10].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=11, longName="PhysicsMeshWire"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[11];
		ParamDef->init("PhysicsMeshWire", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[11].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Draws the simulation mesh, only the active region. From yellow to red, the closer a vertex gets to its max distance. (scalable)", true);
		ParamDefTable[11].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=12, longName="PhysicsMeshSolid"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[12];
		ParamDef->init("PhysicsMeshSolid", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		ParamDefTable[12].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#else

		static HintImpl HintTable[3];
		static Hint* HintPtrTable[3] = { &HintTable[0], &HintTable[1], &HintTable[2], };
		HintTable[0].init("max", physx::PxF64(1.0), true);
		HintTable[1].init("min", physx::PxF64(0.0), true);
		HintTable[2].init("shortDescription", "Same as PhysicsMeshWire but with solid triangles.", true);
		ParamDefTable[12].setHints((const NxParameterized::Hint**)HintPtrTable, 3);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=13, longName="PhysicsMeshNormals"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[13];
		ParamDef->init("PhysicsMeshNormals", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Displays the normals of the physics mesh (base for mesh-mesh skinning).", true);
		ParamDefTable[13].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=14, longName="Skeleton"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[14];
		ParamDef->init("Skeleton", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws lines from parent to child bones. Active bones are displayed in purple, passive in blue.  Only the subset of bones that have a vertex from any of the meshes or a collision volume bound to them will be visible.", true);
		ParamDefTable[14].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=15, longName="BoneFrames"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[15];
		ParamDef->init("BoneFrames", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws the frame of each bone. (scalable)", true);
		ParamDefTable[15].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=16, longName="BoneNames"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[16];
		ParamDef->init("BoneNames", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Displays the name of each bone. (scalable)", true);
		ParamDefTable[16].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=17, longName="Velocities"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[17];
		ParamDef->init("Velocities", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws lines for each simulated vertex' velocity. (scalable)", true);
		ParamDefTable[17].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=18, longName="Wind"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[18];
		ParamDef->init("Wind", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws lines for each simulated vertex' velocity change due to wind, velocity callback or pressure. (scalable)", true);
		ParamDefTable[18].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=19, longName="GraphicalVertexBones"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[19];
		ParamDef->init("GraphicalVertexBones", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws colored lines from each graphical vertex to the bones it uses for skinning. White to black for decreasing weights.", true);
		ParamDefTable[19].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=20, longName="PhysicalVertexBones"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[20];
		ParamDef->init("PhysicalVertexBones", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws colored lines from each simulation vertex to the bones it uses for skinning. White to black for decreasing weights.", true);
		ParamDefTable[20].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=21, longName="CollisionShapes"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[21];
		ParamDef->init("CollisionShapes", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws solid capsules and spheres for the collision shapes.", true);
		ParamDefTable[21].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=22, longName="CollisionShapesWire"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[22];
		ParamDef->init("CollisionShapesWire", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Draws wire capsules and spheres for the collision shapes.", true);
		ParamDefTable[22].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=23, longName="LengthFibers"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[23];
		ParamDef->init("LengthFibers", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the vertical stretching fibers.", true);
		ParamDefTable[23].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=24, longName="CrossSectionFibers"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[24];
		ParamDef->init("CrossSectionFibers", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the horizontal stretching fibers.", true);
		ParamDefTable[24].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=25, longName="BendingFibers"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[25];
		ParamDef->init("BendingFibers", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the bending fibers.", true);
		ParamDefTable[25].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=26, longName="ShearingFibers"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[26];
		ParamDef->init("ShearingFibers", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the shearing fibers.", true);
		ParamDefTable[26].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=27, longName="ZerostretchFibers"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[27];
		ParamDef->init("ZerostretchFibers", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the zero-stretch phases.", true);
		ParamDefTable[27].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=28, longName="TethersActive"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[28];
		ParamDef->init("TethersActive", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the tether constraitns, only active ones (0.99 their length and longer).", true);
		ParamDefTable[28].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=29, longName="TethersInactive"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[29];
		ParamDef->init("TethersInactive", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the tether constraints, only inactive ones (less than 0.99 their length).", true);
		ParamDefTable[29].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=30, longName="VirtualCollision"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[30];
		ParamDef->init("VirtualCollision", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Show the virtual particles. Each has 3 lines to the vertices it connects to.", true);
		ParamDefTable[30].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=31, longName="FiberRange"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[31];
		ParamDef->init("FiberRange", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Combined with fiber debug rendering this visualizes the range where the stiffness of the chosen fiber type is scaled down. It shows how much the cloth is allowed to compress/stretch.", true);
		ParamDefTable[31].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=32, longName="ShowInLocalSpace"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[32];
		ParamDef->init("ShowInLocalSpace", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Enables/Disables debug rendering in local space (experts only!)", true);
		ParamDefTable[32].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=33, longName="GlobalPose"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[33];
		ParamDef->init("GlobalPose", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows the internally stored global pose transform", true);
		ParamDefTable[33].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=34, longName="RecomputeSubmeshes"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[34];
		ParamDef->init("RecomputeSubmeshes", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows the internal reordering of the render mesh asset into physical submeshes and non-simulated parts in shades of gray. This is used to split the cpu skinned part from the skinned part that is skinned the physics mesh.", true);
		ParamDefTable[34].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=35, longName="RecomputeVertices"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[35];
		ParamDef->init("RecomputeVertices", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows the position of the reordered render vertices that are being skinned to the physics mesh. Vertices attached to simulated triangles are rendered orange. Additional vertices along the border are rendered purple, they are needed to prevent visible seams from normal and tangent calculations.", true);
		ParamDefTable[35].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=36, longName="PhysicsMeshIndices"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[36];
		ParamDef->init("PhysicsMeshIndices", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows the indices of the physics mesh", true);
		ParamDefTable[36].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=37, longName="MassScale"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[37];
		ParamDef->init("MassScale", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows red crosses for particles where the mass is scaled for collision purpose", true);
		ParamDefTable[37].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=38, longName="SelfCollision"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[38];
		ParamDef->init("SelfCollision", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows spheres that represent the self collision thickness", true);
		ParamDefTable[38].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=39, longName="SelfCollisionWire"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[39];
		ParamDef->init("SelfCollisionWire", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[1];
		static Hint* HintPtrTable[1] = { &HintTable[0], };
		HintTable[0].init("shortDescription", "Shows spheres that represent the self collision thickness", true);
		ParamDefTable[39].setHints((const NxParameterized::Hint**)HintPtrTable, 1);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=40, longName="SelfCollisionAttenuation"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[40];
		ParamDef->init("SelfCollisionAttenuation", TYPE_F32, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "All connections are drawn that have an attenuation smaller than the given value.\n0.0f disables the visualization, 1.0f shows all attenuated pairs.\n", true);
		HintTable[1].init("shortDescription", "Draws a line between vertices where selfcollision is reduced or turned off.", true);
		ParamDefTable[40].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=41, longName="SolverMode"
	{
		NxParameterized::DefinitionImpl* ParamDef = &ParamDefTable[41];
		ParamDef->init("SolverMode", TYPE_BOOL, NULL, true);

#ifdef NX_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "Shared: Fastest path. It means previous and current positions fit onto shared memory on the GPU.\nMixed: Only slightly slower than Shared. Current positions fit onto shared memory, previous positions need to be streamed in.\nGlobal: Significantly slower than Shared and Mixed. All data is read from global GPU memory. Try to reduce the vertex count and/or split up the asset.\n", true);
		HintTable[1].init("shortDescription", "Displays which solver is used (2.x or 3.x), wether it runs on GPU, and if the simulation data fits into shared memory.", true);
		ParamDefTable[41].setHints((const NxParameterized::Hint**)HintPtrTable, 2);

#endif /* NX_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// SetChildren for: nodeIndex=0, longName=""
	{
		static Definition* Children[41];
		Children[0] = PDEF_PTR(1);
		Children[1] = PDEF_PTR(2);
		Children[2] = PDEF_PTR(3);
		Children[3] = PDEF_PTR(4);
		Children[4] = PDEF_PTR(5);
		Children[5] = PDEF_PTR(6);
		Children[6] = PDEF_PTR(7);
		Children[7] = PDEF_PTR(8);
		Children[8] = PDEF_PTR(9);
		Children[9] = PDEF_PTR(10);
		Children[10] = PDEF_PTR(11);
		Children[11] = PDEF_PTR(12);
		Children[12] = PDEF_PTR(13);
		Children[13] = PDEF_PTR(14);
		Children[14] = PDEF_PTR(15);
		Children[15] = PDEF_PTR(16);
		Children[16] = PDEF_PTR(17);
		Children[17] = PDEF_PTR(18);
		Children[18] = PDEF_PTR(19);
		Children[19] = PDEF_PTR(20);
		Children[20] = PDEF_PTR(21);
		Children[21] = PDEF_PTR(22);
		Children[22] = PDEF_PTR(23);
		Children[23] = PDEF_PTR(24);
		Children[24] = PDEF_PTR(25);
		Children[25] = PDEF_PTR(26);
		Children[26] = PDEF_PTR(27);
		Children[27] = PDEF_PTR(28);
		Children[28] = PDEF_PTR(29);
		Children[29] = PDEF_PTR(30);
		Children[30] = PDEF_PTR(31);
		Children[31] = PDEF_PTR(32);
		Children[32] = PDEF_PTR(33);
		Children[33] = PDEF_PTR(34);
		Children[34] = PDEF_PTR(35);
		Children[35] = PDEF_PTR(36);
		Children[36] = PDEF_PTR(37);
		Children[37] = PDEF_PTR(38);
		Children[38] = PDEF_PTR(39);
		Children[39] = PDEF_PTR(40);
		Children[40] = PDEF_PTR(41);

		ParamDefTable[0].setChildren(Children, 41);
	}

	mBuiltFlag = true;

}
void ClothingDebugRenderParams::initStrings(void)
{
}

void ClothingDebugRenderParams::initDynamicArrays(void)
{
}

void ClothingDebugRenderParams::initDefaults(void)
{

	freeStrings();
	freeReferences();
	freeDynamicArrays();
	Actors = bool(true);
	SkinnedPositions = physx::PxF32(0);
	Backstop = bool(false);
	BackstopPrecise = physx::PxF32(0);
	MaxDistance = bool(0);
	MaxDistanceInwards = bool(0);
	SkinMapAll = bool(0);
	SkinMapBad = bool(0);
	SkinMapActual = bool(0);
	SkinMapInvalidBary = bool(0);
	PhysicsMeshWire = physx::PxF32(0);
	PhysicsMeshSolid = physx::PxF32(0);
	PhysicsMeshNormals = physx::PxF32(0);
	Skeleton = bool(0);
	BoneFrames = physx::PxF32(0);
	BoneNames = physx::PxF32(0);
	Velocities = physx::PxF32(0);
	Wind = physx::PxF32(0);
	GraphicalVertexBones = bool(0);
	PhysicalVertexBones = bool(0);
	CollisionShapes = bool(false);
	CollisionShapesWire = bool(false);
	LengthFibers = bool(false);
	CrossSectionFibers = bool(false);
	BendingFibers = bool(false);
	ShearingFibers = bool(false);
	ZerostretchFibers = bool(false);
	TethersActive = bool(false);
	TethersInactive = bool(false);
	VirtualCollision = bool(false);
	FiberRange = bool(false);
	ShowInLocalSpace = bool(false);
	GlobalPose = bool(false);
	RecomputeSubmeshes = bool(false);
	RecomputeVertices = bool(false);
	PhysicsMeshIndices = bool(false);
	MassScale = bool(false);
	SelfCollision = bool(false);
	SelfCollisionWire = bool(false);
	SelfCollisionAttenuation = physx::PxF32(false);
	SolverMode = bool(false);

	initDynamicArrays();
	initStrings();
	initReferences();
}

void ClothingDebugRenderParams::initReferences(void)
{
}

void ClothingDebugRenderParams::freeDynamicArrays(void)
{
}

void ClothingDebugRenderParams::freeStrings(void)
{
}

void ClothingDebugRenderParams::freeReferences(void)
{
}

} // namespace clothing
} // namespace apex
} // namespace physx
