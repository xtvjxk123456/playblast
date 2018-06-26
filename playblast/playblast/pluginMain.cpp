//-
// Copyright 2012 Autodesk, Inc.  All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk license agreement
// provided at the time of installation or download, or which otherwise
// accompanies this software in either electronic or hard copy form.
//+

#include <maya/MString.h>
#include <maya/MFnPlugin.h>
#include <maya/MViewport2Renderer.h>

#include "playblastRenderOverride.h"

static playblastRenderOverride* playblastRenderOverrideInstance = NULL;

MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj, PLUGIN_COMPANY, "1.0", "Any");

	// Register override


	MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
	if (renderer)
	{
		if (!playblastRenderOverrideInstance)
		{
			playblastRenderOverrideInstance = new playblastRenderOverride("playblastRenderOverride");
			renderer->registerOverride(playblastRenderOverrideInstance);
		}
	}

	return MStatus::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin plugin(obj);

	MHWRender::MRenderer* renderer = MHWRender::MRenderer::theRenderer();
	if (renderer)
	{
		if (playblastRenderOverrideInstance)
		{
			renderer->deregisterOverride(playblastRenderOverrideInstance);
			delete playblastRenderOverrideInstance;
		}
		playblastRenderOverrideInstance = NULL;
	}

	return MStatus::kSuccess;
}

