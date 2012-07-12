////////////////////////////////////////////////////////////
//
// DAGON - An Adventure Game Engine
// Copyright (c) 2011 Senscape s.r.l.
// All rights reserved.
//
// NOTICE: Senscape permits you to use, modify, and
// distribute this file in accordance with the terms of the
// license agreement accompanying it.
//
////////////////////////////////////////////////////////////

#ifndef DG_EFFECTSLIB_H
#define DG_EFFECTSLIB_H

////////////////////////////////////////////////////////////
// NOTE: This header file should never be included directly.
// It's auto-included by DGProxy.h
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "DGEffectsManager.h"

////////////////////////////////////////////////////////////
// Interface
////////////////////////////////////////////////////////////

static int DGEffectsLibGet(lua_State *L) {
    DGEffectsManager* effectsManager = &DGEffectsManager::getInstance();
    
	const char *key = luaL_checkstring(L, 2);
	
    if (strcmp(key, "brightness") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectAdjustBrightness) * 100.0f);
        return 1;
    }
    
	if (strcmp(key, "contrast") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectAdjustContrast) * 100.0f);
        return 1;
    }
    
	if (strcmp(key, "saturation") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectAdjustSaturation) * 100.0f);
        return 1;
    }
    
	if (strcmp(key, "motionBlur") == 0) {
        lua_pushnumber(L, (1000.0f - effectsManager->value(DGEffectMotionBlurIntensity) * 100.0f));
        return 1;
    }
    
	if (strcmp(key, "noise") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectNoiseIntensity) * 100.0f);
        return 1;
    }
    
	if (strcmp(key, "sepia") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectSepiaIntensity) * 100.0f);
        return 1;
    }
    
	if (strcmp(key, "sharpen") == 0) {
        lua_pushnumber(L, effectsManager->value(DGEffectSharpenIntensity) * 100.0f);
        return 1;
    }

	return 0;
}

static int DGEffectsLibSet(lua_State *L) {
    DGEffectsManager* effectsManager = &DGEffectsManager::getInstance();
    
    float value = (float)(luaL_checknumber(L, 3) / 100.0f);
	const char *key = luaL_checkstring(L, 2);
	
	if (strcmp(key, "brightness") == 0) {
        effectsManager->setValue(DGEffectAdjustBrightness, value);
    }
    
	if (strcmp(key, "contrast") == 0) {
        effectsManager->setValue(DGEffectAdjustContrast, value);
    }
    
	if (strcmp(key, "saturation") == 0) {
        effectsManager->setValue(DGEffectAdjustSaturation, value);
    }
    
    // Special case to enable/disable adjustment if three values are normal
    if (effectsManager->value(DGEffectAdjustBrightness) == 1.0f &&
        effectsManager->value(DGEffectAdjustSaturation) == 1.0f &&
        effectsManager->value(DGEffectAdjustContrast) == 1.0f) {
        effectsManager->setEnabled(DGEffectAdjust, false);
    }
    else effectsManager->setEnabled(DGEffectAdjust, true);
    
	if (strcmp(key, "motionBlur") == 0) {
        if (value) {
            effectsManager->setEnabled(DGEffectMotionBlur, true);
            effectsManager->setValue(DGEffectMotionBlurIntensity, (10.0f - value));
        }
        else effectsManager->setEnabled(DGEffectMotionBlur, false);
    }
    
	if (strcmp(key, "noise") == 0) {
        if (value) {
            effectsManager->setEnabled(DGEffectNoise, true);
            effectsManager->setValue(DGEffectNoiseIntensity, value);
        }
        else effectsManager->setEnabled(DGEffectNoise, false);
    }
    
	if (strcmp(key, "sepia") == 0) {
        if (value) {
            effectsManager->setEnabled(DGEffectSepia, true);
            effectsManager->setValue(DGEffectSepiaIntensity, value);
        }
        else effectsManager->setEnabled(DGEffectSepia, false);
    }
    
	if (strcmp(key, "sharpen") == 0) {
        if (value) {
            effectsManager->setEnabled(DGEffectSharpen, true);
            effectsManager->setValue(DGEffectSharpenIntensity, value);
        }
        else effectsManager->setEnabled(DGEffectSharpen, false);
    }
    
 	return 0;
}

////////////////////////////////////////////////////////////
// Static definitions
////////////////////////////////////////////////////////////

const struct luaL_Reg DGEffectsLib[] =
{
    {"__index", DGEffectsLibGet},
    {"__newindex", DGEffectsLibSet},
    {NULL, NULL}
};

#endif // DG_EFFECTSLIB_H
