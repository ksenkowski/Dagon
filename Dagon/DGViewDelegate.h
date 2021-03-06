////////////////////////////////////////////////////////////
//
// DAGON - An Adventure Game Engine
// Copyright (c) 2012 Senscape s.r.l.
// All rights reserved.
//
// NOTICE: Senscape permits you to use, modify, and
// distribute this file in accordance with the terms of the
// license agreement accompanying it.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#import "DGPlatform.h"

////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////

class DGConfig;
class DGControl;

////////////////////////////////////////////////////////////
// Interface
////////////////////////////////////////////////////////////

@interface DGViewDelegate : NSView {
    DGConfig* config;
    DGControl* control;
    
    BOOL isMouseInside; 
	NSOpenGLPixelFormat* pixelFormat;
	NSOpenGLContext* glContext;
    NSTrackingRectTag boundsTrackingTag;
}

- (void)update;

@end
