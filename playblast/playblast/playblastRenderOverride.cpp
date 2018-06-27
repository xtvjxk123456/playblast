#include "playblastRenderOverride.h"
#include "playblastRenderOperation.h"


playblastRenderOverride::playblastRenderOverride(const MString& name)
	: MRenderOverride(name)
	, mUIName("Playblast viewport") {

}


playblastRenderOverride::~playblastRenderOverride() {

}

MHWRender::DrawAPI playblastRenderOverride::supportedDrawAPIs() const
{
	return (MHWRender::kOpenGL | MHWRender::kDirectX11);
}

bool playblastRenderOverride::startOperationIterator()
{
	mCurrentOperation = 0;
	return true;
}

MHWRender::MRenderOperation* playblastRenderOverride::renderOperation()
{
	if (mCurrentOperation >= 0 && mCurrentOperation < 4)
	{
		// Skip empty and disabled operations
		//

		if (mRenderOperations[mCurrentOperation])
		{
			return mRenderOperations[mCurrentOperation];
		}
	}
	return NULL;
}

bool playblastRenderOverride::nextRenderOperation()
{
	mCurrentOperation++;
	if (mCurrentOperation < 4)
	{
		return true;
	}
	return false;
}


MStatus playblastRenderOverride::updateRenderOperations()
{
	bool initOperations = true;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (mRenderOperations[i])
			initOperations = false;
	}

	if (initOperations)
	{
		// 1.Regular scene render
		MHWRender::MSceneRender * sceneOp = new MHWRender::MSceneRender("scene");
		mRenderOperations[0] = sceneOp;

		// 2. There ops are for playback
		//todo
		mRenderOperations[1] = new PlayblastRenderOperation("test_playblast", this);

		// 3.Generic screen blit - always want to do this
		mRenderOperations[2] = new MHWRender::MPresentTarget("present");

	}
	mCurrentOperation = -1;

	MStatus haveOperations = MStatus::kSuccess;
	for (unsigned int i = 0; i < 3; i++)
	{
		if (!mRenderOperations[i])
		{
			haveOperations = MStatus::kFailure;
			break;
		}
	}
	if (haveOperations != MStatus::kSuccess)
		return haveOperations;

	return MStatus::kSuccess;
}

MStatus playblastRenderOverride::setup(const MString& destination) {
	// Firewall checks
	MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
	if (!renderer) return MStatus::kFailure;

	/*const MHWRender::MShaderManager* shaderMgr = renderer->getShaderManager();
	if (!shaderMgr) return MStatus::kFailure;*/

	const MHWRender::MRenderTargetManager *targetManager = renderer->getRenderTargetManager();
	if (!targetManager) return MStatus::kFailure;

	//上面是测试环境
	MStatus status = updateRenderOperations();

	if (status != MStatus::kSuccess)
		return status;
	return MStatus::kSuccess;

}
