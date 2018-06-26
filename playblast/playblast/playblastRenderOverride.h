#ifndef PLAYBLASTRENDEROVERRIDE_H
#define PLAYBLASTRENDEROVERRIDE_H

#include <maya/MString.h>
#include <maya/MColor.h>
#include <maya/MViewport2Renderer.h>
#include <maya/MTime.h>
#include <map>


class playblastRenderOverride : public MHWRender::MRenderOverride
{
public:

	playblastRenderOverride(const MString& name);
	virtual ~playblastRenderOverride();

	//下面应该是必须的设置的方法
	virtual MHWRender::DrawAPI supportedDrawAPIs() const;
	virtual bool startOperationIterator();
	virtual MHWRender::MRenderOperation * renderOperation();
	virtual bool nextRenderOperation();
	virtual MStatus setup(const MString& destination);
	//virtual MStatus cleanup();
	virtual MString uiName() const
	{
		return mUIName;
	}
	

protected:
	MString mUIName;
	int mCurrentOperation;	
	MHWRender::MRenderOperation * mRenderOperations[3];

	MStatus updateRenderOperations();
};
#endif 

