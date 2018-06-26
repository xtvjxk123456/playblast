#include "playblastRenderOperation.h"

PlayblastRenderOperation::PlayblastRenderOperation(const MString &name, MHWRender::MRenderOverride *override)
	: MHWRender::MUserRenderOperation(name)
	, mOverride(override)

{
}

PlayblastRenderOperation::~PlayblastRenderOperation()
{
	mOverride = NULL;

}


MStatus PlayblastRenderOperation::execute(const MHWRender::MDrawContext & drawContext)
{
	// Get a copy of the current target
	
	return MStatus::kSuccess;
}