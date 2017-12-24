//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-04
// Updated : 2006-01-04
// Licence : This source is under GNU LGPL licence
// File    : gtx_fast_square_root.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////
// Note:
// - Sqrt optimisation based on Newton's method, 
// www.gamedev.net/community/forums/topic.asp?topic id=139956
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_fast_square_root_h__
#define __gtx_fast_square_root_h__

//#define GLM_GTX_fast_square_root 1
#include "../glm.h"

namespace glm
{
    float fastSqrtGTX(float x);
    vec2 fastSqrtGTX(const vec2& x);
    vec3 fastSqrtGTX(const vec3& x);
    vec4 fastSqrtGTX(const vec4& x);

    float fastInversesqrtGTX(float x);
    vec2 fastInversesqrtGTX(const vec2& x);
    vec3 fastInversesqrtGTX(const vec3& x);
    vec4 fastInversesqrtGTX(const vec4& x);

    float fastLengthGTX(float x);
    float fastLengthGTX(const vec2& x);
    float fastLengthGTX(const vec3& x);
    float fastLengthGTX(const vec4& x);

    float fastDistanceGTX(float x, float y);
    float fastDistanceGTX(const vec2& x, const vec2& y);
    float fastDistanceGTX(const vec3& x, const vec3& y);
    float fastDistanceGTX(const vec4& x, const vec4& y);

    float fastNormalizeGTX(float x);
    vec2 fastNormalizeGTX(const vec2& x);
    vec3 fastNormalizeGTX(const vec3& x);
    vec4 fastNormalizeGTX(const vec4& x);
}

#endif//__gtx_fast_square_root_h__
