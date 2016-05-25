//! @file detailsengine.h
//! @brief Substance Framework Engine/Linker wrapper definition
//! @author Christophe Soum - Allegorithmic
//! @date 20111031
//! @copyright Allegorithmic. All rights reserved.
//!

#ifndef _SUBSTANCE_FRAMEWORK_DETAILS_DETAILSENGINE_H
#define _SUBSTANCE_FRAMEWORK_DETAILS_DETAILSENGINE_H

#include <string>
#include "detailsgraphbinary.h"
#include "detailssync.h"
#include "SubstanceCallbacks.h"

#include "substance_public.h"

namespace Substance
{

struct RenderOptions;

namespace Details
{

class RenderJob;
struct LinkGraphs;
struct LinkContext;

//! @brief Substance Engine Wrapper
class Engine
{
public:
	//! @brief Constructor
	//! @param renderOptions Initial render options.
	Engine(const RenderOptions& renderOptions);

	//! @brief Destructor
	//! @pre Must be already released (releaseEngine())
	~Engine();

	//! @brief Destroy engine (handle and context)
	//! @pre No render currently running
	void releaseEngine();
	
	//! @brief Accessor on current Substance Handle
	//! @return Return the current handle or NULL not already linked
	SubstanceHandle* getHandle() const { return mHandle; }
	
	//! @brief Link/Relink all states in pending render jobs
	//! @param renderJobBegin Begin of chained list of render jobs to link
	//! @param renderJobLast Last job of chained list of render jobs to link
	//! @return Return true if link process succeed
	bool link(RenderJob* renderJobBegin,const RenderJob* renderJobLast);
	
	//! @brief Flush internal engine queue
	//! @post Engine render queue is flushed
	void flush();
	
	//! @brief Stop any generation
	//! Thread safe stop call on current handle if present 
	//! @note Called from user thread
	void stop();

	//! @brief Set new memory budget and CPU usage.
	//! @param renderOptions New render options to use.
	//! @note This function can be called at any time, from any thread.
	//!	@return Return true if options are immediately processed.
	bool setOptions(const RenderOptions& renderOptions);

	//! @brief 
	void clearCache();
	
	//! @brief Linker Collision UID callback implementation
	//! @param collisionType Output or input collision flag
	//! @param previousUid Initial UID that collide
	//! @param newUid New UID generated
	//! @note Called by linker callback
	void callbackLinkerUIDCollision(
		SubstanceLinkerUIDCollisionType collisionType,
		uint32 previousUid,
		uint32 newUid);

	//! @brief Accessor on UID of this instance (used for cache eviction) 
	//! Each instance has a different UID in the current execution context.
	uint32 getInstanceUid() const { return mInstanceUid; }
	
	//! @brief Enqueue texture for deletion, texture ownership is grabbed
	//! @warning Can be called from user thread
	void enqueueRelease(const SubstanceTexture& texture);

	//! @brief Release enqueued textures (enqueueRelease())
	//! @brief Must be called from render thread
	void releaseTextures();
	
protected:

	//! @brief Engine Contexts class
	class Context
	{
	public:
		//! @brief Constructor, create Substance Context
		Context(Engine& parent, RenderCallbacks* callbacks);
		
		//! @brief Destructor, release Substance Context
		~Context();
		
		//! @brief Accessor on Substance Engine Context
		SubstanceContext *getContext() const { return mContext; }

	protected:
		//! @brief Parent engine reference
		Engine& mParent;

		//! @brief Substance Engine Context
		SubstanceContext *mContext;
	};  // class Context

	//! @brief List of textures to delete
	typedef TArray<SubstanceTexture> TexturesList;
	
	//! @brief Last UID used, used to generate Engine::mInstanceUid
	static uint32 mLastInstanceUid;
	
	//! @brief UID of this instance (used for cache eviction) 
	//! Each instance has a different UID in the current execution context.
	const uint32 mInstanceUid;
	
	//! @brief Context singleton instance
	static std::weak_ptr<Context> mContextGlobal;
	
	//! @brief This instance Context (create on render thread)
	std::auto_ptr<Context> mContextInstance;
	
	//! @brief SBSBIN data, double buffer
	//! Two buffers are used for cache transfer
	//! @invariant At least one buffer is empty
	std::string mSbsbinDatas[2];
	
	//! @brief Linker cache data generated by linker
	const unsigned char* mLinkerCacheData;
	
	//! @brief The current substance handle
	//! NULL if not yet linked
	SubstanceHandle *mHandle;
	
	//! @brief Mutex on handle stop/create/switch
	//! Used for stop() thread safe action
	Sync::mutex mMutexHandle;
	
	//! @brief Substance Linker Context
	//! One linker context/handle per Renderer to avoid concurrency issues
	SubstanceLinkerContext *mLinkerContext;	
	
	//! @brief Substance Linker Handle
	//! One linker context/handle per Renderer to avoid concurrency issues
	SubstanceLinkerHandle *mLinkerHandle;
	
	//! @brief Substance Engine hard resources used by handle
	SubstanceHardResources mHardResources;
	
	//! @brief Contains current filled binary, used during link (by callbacks)
	LinkContext *mCurrentLinkContext;

	//! @brief List of textures to delete
	//! R/W access thread safety ensure by mMutexToRelease.
	TexturesList mToReleaseTextures;

	//! @brief Mutex on mToReleaseTextures access
	Sync::mutex mMutexToRelease;

	//! @brief Pending textures to release into mToReleaseTextures
	//! Can be set from any thread. Unset from render thread.
	volatile bool mPendingReleaseTextures;
	
	//! @brief Fill Graph binaries w/ new Engine handle SBSBIN indices
	//! @param linkGraphs Contains Graph binaries to fill indices
	void fillIndices(LinkGraphs& linkGraphs) const;

	//! @brief Create Linker handle and context
	void createLinker();

	//! @brief Release linker handle and context
	void releaseLinker();
	
	//! @brief Fill hard resources from render options
	static void fillHardResources(
		SubstanceHardResources& hardRsc,
		const RenderOptions& renderOptions);
	
private:
	Engine(const Engine&);
	const Engine& operator=(const Engine&);	
};  // class Engine


} // namespace Details
} // namespace Substance

#endif // ifndef _SUBSTANCE_FRAMEWORK_DETAILS_DETAILSENGINE_H
