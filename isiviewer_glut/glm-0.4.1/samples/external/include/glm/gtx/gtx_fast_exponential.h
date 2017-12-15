//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-09
// Updated : 2006-01-09
// Licence : This source is under GNU LGPL licence
// File    : gtx_fast_exponential.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_fast_exponential_h__
#define __gtx_fast_exponential_h__

#define GLM_GTX_fast_exponential 1
#include "../glm.h"

namespace glm
{
    float fastPowGTX(float x, float y);
    template <typename T> _xvec2<T> fastPowGTX(const _xvec2<T>& x, const _xvec2<T>& y);
    template <typename T> _xvec3<T> fastPowGTX(const _xvec3<T>& x, const _xvec3<T>& y);
    template <typename T> _xvec4<T> fastPowGTX(const _xvec4<T>& x, const _xvec4<T>& y);

    float fastPowGTX(float x, int y);
    template <typename T> _xvec2<T> fastPowGTX(const _xvec2<T>& x, const _xvec2<int>& y);
    template <typename T> _xvec3<T> fastPowGTX(const _xvec3<T>& x, const _xvec3<int>& y);
    template <typename T> _xvec4<T> fastPowGTX(const _xvec4<T>& x, const _xvec4<int>& y);

    float fastExpGTX(float x);
    template <typename T> _xvec2<T> fastExpGTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastExpGTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastExpGTX(const _xvec4<T>& x);

    float fastLogGTX(float x);
    template <typename T> _xvec2<T> fastLogGTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastLogGTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastLogGTX(const _xvec4<T>& x);

    float fastExp2GTX(float x);
    template <typename T> _xvec2<T> fastExp2GTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastExp2GTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastExp2GTX(const _xvec4<T>& x);

    float fastLog2GTX(float x);
    template <typename T> _xvec2<T> fastLog2GTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastLog2GTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastLog2GTX(const _xvec4<T>& x);

    float fastLnGTX(float x);
    template <typename T> _xvec2<T> fastLnGTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastLnGTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastLnGTX(const _xvec4<T>& x);
}

#endif//__gtx_fast_exponential_h__
