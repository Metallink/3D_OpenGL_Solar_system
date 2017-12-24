//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-08
// Updated : 2006-01-08
// Licence : This source is under GNU LGPL licence
// File    : gtx_fast_trigonometry.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0

#ifndef __gtx_fast_trigonometry_h__
#define __gtx_fast_trigonometry_h__

#define GLM_GTX_fast_trigonometry 1
#include "../glm.h"

namespace glm
{
    float fastSinGTX(float angle);
    template <typename T> _xvec2<T> fastSinGTX(const _xvec2<T>& angle);
    template <typename T> _xvec3<T> fastSinGTX(const _xvec3<T>& angle);
    template <typename T> _xvec4<T> fastSinGTX(const _xvec4<T>& angle);

    float fastCosGTX(float angle);
    template <typename T> _xvec2<T> fastCosGTX(const _xvec2<T>& angle);
    template <typename T> _xvec3<T> fastCosGTX(const _xvec3<T>& angle);
    template <typename T> _xvec4<T> fastCosGTX(const _xvec4<T>& angle);

    float fastTanGTX(float angle);
    template <typename T> _xvec2<T> fastTanGTX(const _xvec2<T>& angle);
    template <typename T> _xvec3<T> fastTanGTX(const _xvec3<T>& angle);
    template <typename T> _xvec4<T> fastTanGTX(const _xvec4<T>& angle);

    float fastAsinGTX(float x);
    template <typename T> _xvec2<T> fastAsinGTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastAsinGTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastAsinGTX(const _xvec4<T>& x);

    float fastAcosGTX(float x);
    template <typename T> _xvec2<T> fastAcosGTX(const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastAcosGTX(const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastAcosGTX(const _xvec4<T>& x);

    float fastAtanGTX(float y, float x);
    template <typename T> _xvec2<T> fastAtanGTX(const _xvec2<T>& y, const _xvec2<T>& x);
    template <typename T> _xvec3<T> fastAtanGTX(const _xvec3<T>& y, const _xvec3<T>& x);
    template <typename T> _xvec4<T> fastAtanGTX(const _xvec4<T>& y, const _xvec4<T>& x);

    float fastAtanGTX(float y_over_x);
    template <typename T> _xvec2<T> fastAtanGTX(const _xvec2<T>& y_over_x);
    template <typename T> _xvec3<T> fastAtanGTX(const _xvec3<T>& y_over_x);
    template <typename T> _xvec4<T> fastAtanGTX(const _xvec4<T>& y_over_x);
}

#endif//__gtx_fast_trigonometry_h__
