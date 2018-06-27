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

bool PlayblastRenderOperation::hasUIDrawables() const
{
	return true;
}

void PlayblastRenderOperation::addUIDrawables(MHWRender::MUIDrawManager & drawManager, const MHWRender::MFrameContext & frameContext)
{
	drawManager.beginDrawable();

	drawManager.setColor(MColor(0.95f, 0.5f, 0.1f));
	drawManager.text(MPoint(0, 2, 0), MString("UI draw test in user operation"));
	drawManager.line(MPoint(0, 0, 0), MPoint(0, 2, 0));
	drawManager.setColor(MColor(1.0f, 1.0f, 1.0f));
	drawManager.sphere(MPoint(0, 2, 0), 0.8, false);
	drawManager.setColor(MColor(0.95f, 0.5f, 0.1f, 0.4f));
	drawManager.sphere(MPoint(0, 2, 0), 0.8, true);
	drawManager.endDrawable();
}
