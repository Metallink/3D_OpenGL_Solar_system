//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-24
// Updated : 2006-01-08
// Licence : This source is under GNU LGPL licence
// File    : gtx_integer.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0

#ifndef __gtx_integer_h__
#define __gtx_integer_h__

#define GLM_GTX_integer 1
#include "../glm.h"

namespace glm
{
    int powGTX(int x, int y);
    _xvec2<int> powGTX(const _xvec2<int>& x, const _xvec2<int>& y);
    _xvec3<int> powGTX(const _xvec3<int>& x, const _xvec3<int>& y);
    _xvec4<int> powGTX(const _xvec4<int>& x, const _xvec4<int>& y);

    int sqrtGTX(int x);
    _xvec2<int> sqrtGTX(const _xvec2<int>& x);
    _xvec3<int> sqrtGTX(const _xvec3<int>& x);
    _xvec4<int> sqrtGTX(const _xvec4<int>& x);

    int absGTX(int x);
    _xvec2<int> absGTX(const _xvec2<int>& x);
    _xvec3<int> absGTX(const _xvec3<int>& x);
    _xvec4<int> absGTX(const _xvec4<int>& x);

    int signGTX(int x);
    _xvec2<int> signGTX(const _xvec2<int>& x);
    _xvec3<int> signGTX(const _xvec3<int>& x);
    _xvec4<int> signGTX(const _xvec4<int>& x);

    int modGTX(int x, int y);
    _xvec2<int> modGTX(const _xvec2<int>& x, int y);
    _xvec3<int> modGTX(const _xvec3<int>& x, int y);
    _xvec4<int> modGTX(const _xvec4<int>& x, int y);
    _xvec2<int> modGTX(const _xvec2<int>& x, const _xvec2<int>& y);
    _xvec3<int> modGTX(const _xvec3<int>& x, const _xvec3<int>& y);
    _xvec4<int> modGTX(const _xvec4<int>& x, const _xvec4<int>& y);

    int minGTX(int x, int y);
    _xvec2<int> minGTX(const _xvec2<int>& x, int y);
    _xvec3<int> minGTX(const _xvec3<int>& x, int y);
    _xvec4<int> minGTX(const _xvec4<int>& x, int y);
    _xvec2<int> minGTX(const _xvec2<int>& x, const _xvec2<int>& y);
    _xvec3<int> minGTX(const _xvec3<int>& x, const _xvec3<int>& y);
    _xvec4<int> minGTX(const _xvec4<int>& x, const _xvec4<int>& y);

    int maxGTX(int x, int y);
    _xvec2<int> maxGTX(const _xvec2<int>& x, int y);
    _xvec3<int> maxGTX(const _xvec3<int>& x, int y);
    _xvec4<int> maxGTX(const _xvec4<int>& x, int y);
    _xvec2<int> maxGTX(const _xvec2<int>& x, const _xvec2<int>& y);
    _xvec3<int> maxGTX(const _xvec3<int>& x, const _xvec3<int>& y);
    _xvec4<int> maxGTX(const _xvec4<int>& x, const _xvec4<int>& y);

    int clampGTX(int x, int minVal, int maxVal);
    _xvec2<int> clampGTX(const _xvec2<int>& x, int minVal, int maxVal);
    _xvec3<int> clampGTX(const _xvec3<int>& x, int minVal, int maxVal);
    _xvec4<int> clampGTX(const _xvec4<int>& x, int minVal, int maxVal);
    _xvec2<int> clampGTX(const _xvec2<int>& x, const _xvec2<int>& minVal, const _xvec2<int>& maxVal);
    _xvec3<int> clampGTX(const _xvec3<int>& x, const _xvec3<int>& minVal, const _xvec3<int>& maxVal);
    _xvec4<int> clampGTX(const _xvec4<int>& x, const _xvec4<int>& minVal, const _xvec4<int>& maxVal);

    int factorialGTX(int x);
    _xvec2<int> factorialGTX(const _xvec2<int>& x);
    _xvec3<int> factorialGTX(const _xvec3<int>& x);
    _xvec4<int> factorialGTX(const _xvec4<int>& x);
}

#endif//__gtx_integer_h__
