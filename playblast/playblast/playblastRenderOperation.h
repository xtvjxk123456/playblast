#ifndef PLAYBLASTRENDEROPERATION_H
#define PLAYBLASTRENDEROPERATION_H

#include <maya/MViewport2Renderer.h>

class PlayblastRenderOperation : public MHWRender::MUserRenderOperation
{
public:
	PlayblastRenderOperation(const MString &name, MHWRender::MRenderOverride *override);
	virtual ~PlayblastRenderOperation();

	virtual MStatus execute(const MHWRender::MDrawContext & drawContext);

protected:
	MHWRender::MRenderOverride * mOverride;
	
};


#endif // !PLAYBLASTRENDEROPERATION_H

