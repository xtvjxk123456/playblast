#ifndef PLAYBLASTRENDEROPERATION_H
#define PLAYBLASTRENDEROPERATION_H

#include <maya/MViewport2Renderer.h>

class PlayblastRenderOperation : public MHWRender::MUserRenderOperation
{
public:
	PlayblastRenderOperation(const MString &name, MHWRender::MRenderOverride *override);
	virtual ~PlayblastRenderOperation();

	virtual MStatus execute(const MHWRender::MDrawContext & drawContext);
	virtual bool hasUIDrawables() const;
	virtual void addUIDrawables(MHWRender::MUIDrawManager& drawManager,const MHWRender::MFrameContext& frameContext);
	
protected:
	MHWRender::MRenderOverride * mOverride;
	
};


#endif // !PLAYBLASTRENDEROPERATION_H

