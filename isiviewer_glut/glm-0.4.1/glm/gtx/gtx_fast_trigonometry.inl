//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-08
// Updated : 2006-01-08
// Licence : This source is under GNU LGPL licence
// File    : gtx_fast_trigonometry.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_fast_trigonometry_inl__
#define __gtx_fast_trigonometry_inl__

#include "gtx_fast_trigonometry.h"

namespace glm
{
    // sin
    inline float fastSinGTX(float x)
    {
        return x - ((x * x * x) / 6.0f) + ((x * x * x * x * x) / 120.0f) - ((x * x * x * x * x * x * x) / 5040.f);
    }

    template <typename T> 
    inline _xvec2<T> fastSinGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastSinGTX(x.x),
            glm::fastSinGTX(x.y));
    }

    template <typename T> 
    inline _xvec3<T> fastSinGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastSinGTX(x.x),
            glm::fastSinGTX(x.y),
            glm::fastSinGTX(x.z));
    }

    template <typename T> 
    inline _xvec4<T> fastSinGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastSinGTX(x.x),
            glm::fastSinGTX(x.y),
            glm::fastSinGTX(x.z),
            glm::fastSinGTX(x.w));
    }

    // cos
    inline float fastCosGTX(float x)
    {
        return 1.0f - (x * x * 0.5f) + (x * x * x * x * 0.041666666666f) - (x * x * x * x * x * x * 0.00138888888888f);
    }

    template <typename T> 
    inline _xvec2<T> fastCosGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastCosGTX(x.x),
            glm::fastCosGTX(x.y));
    }

    template <typename T> 
    inline _xvec3<T> fastCosGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastCosGTX(x.x),
            glm::fastCosGTX(x.y),
            glm::fastCosGTX(x.z));
    }

    template <typename T> 
    inline _xvec4<T> fastCosGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastCosGTX(x.x),
            glm::fastCosGTX(x.y),
            glm::fastCosGTX(x.z),
            glm::fastCosGTX(x.w));
    }

    // tan
    inline float fastTanGTX(float x)
    {
        return x + (x * x * x * 0.3333333333f) + (x * x * x * x * x * 0.1333333333333f) + (x * x * x * x * x * x * x * 0.0539682539f);
    }

    template <typename T> 
    inline _xvec2<T> fastTanGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastTanGTX(x.x),
            glm::fastTanGTX(x.y));
    }

    template <typename T> 
    inline _xvec3<T> fastTanGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastTanGTX(x.x),
            glm::fastTanGTX(x.y),
            glm::fastTanGTX(x.z));
    }

    template <typename T> 
    inline _xvec4<T> fastTanGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastTanGTX(x.x),
            glm::fastTanGTX(x.y),
            glm::fastTanGTX(x.z),
            glm::fastTanGTX(x.w));
    }

    // asin
    inline float fastAsinGTX(float x)
    {
        return x + (x * x * x * 0.166666667f) + (x * x * x * x * x * 0.075f) + (x * x * x * x * x * x * x * 0.0446428571f) + (x * x * x * x * x * x * x * x * x * 0.0303819444f);// + (x * x * x * x * x * x * x * x * x * x * x * 0.022372159f);
    }

    template <typename T> _xvec2<T> fastAsinGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastAsinGTX(x.x),
            glm::fastAsinGTX(x.y));
    }

    template <typename T> _xvec3<T> fastAsinGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastAsinGTX(x.x),
            glm::fastAsinGTX(x.y),
            glm::fastAsinGTX(x.z));
    }

    template <typename T> _xvec4<T> fastAsinGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastAsinGTX(x.x),
            glm::fastAsinGTX(x.y),
            glm::fastAsinGTX(x.z),
            glm::fastAsinGTX(x.w));
    }

    // acos
    inline float fastAcosGTX(float x)
    {
        return 1.5707963267948966192313216916398f - glm::fastAsinGTX(x); //(PI / 2)
    }

    template <typename T> _xvec2<T> fastAcosGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastAcosGTX(x.x),
            glm::fastAcosGTX(x.y));
    }

    template <typename T> _xvec3<T> fastAcosGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastAcosGTX(x.x),
            glm::fastAcosGTX(x.y),
            glm::fastAcosGTX(x.z));
    }

    template <typename T> _xvec4<T> fastAcosGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastAcosGTX(x.x),
            glm::fastAcosGTX(x.y),
            glm::fastAcosGTX(x.z),
            glm::fastAcosGTX(x.w));
    }

    // atan
    inline float fastAtanGTX(float y, float x)
    {
        float sgn = glm::sign(y) * glm::sign(x);
        return glm::abs(fastAtanGTX(y / x)) * sgn;
    }

    template <typename T> 
    inline _xvec2<T> fastAtanGTX(const _xvec2<T>& y, const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastAtanGTX(y.x, x.x),
            glm::fastAtanGTX(y.y, x.y));
    }

    template <typename T> 
    inline _xvec3<T> fastAtanGTX(const _xvec3<T>& y, const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastAtanGTX(y.x, x.x),
            glm::fastAtanGTX(y.y, x.y),
            glm::fastAtanGTX(y.z, x.z));
    }

    template <typename T> 
    inline _xvec4<T> fastAtanGTX(const _xvec4<T>& y, const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastAtanGTX(y.x, x.x),
            glm::fastAtanGTX(y.y, x.y),
            glm::fastAtanGTX(y.z, x.z),
            glm::fastAtanGTX(y.w, x.w));
    }

    inline float fastAtanGTX(float x)
    {
        return x - (x * x * x * 0.333333333333f) + (x * x * x * x * x * 0.2f) - (x * x * x * x * x * x * x * 0.1428571429f) + (x * x * x * x * x * x * x * x * x * 0.111111111111f) - (x * x * x * x * x * x * x * x * x * x * x * 0.0909090909f);
    }

    template <typename T> 
    inline _xvec2<T> fastAtanGTX(const _xvec2<T>& x)
    {
        return _xvec2<T>(
            glm::fastAtanGTX(x.x),
            glm::fastAtanGTX(x.y));
    }

    template <typename T> 
    inline _xvec3<T> fastAtanGTX(const _xvec3<T>& x)
    {
        return _xvec3<T>(
            glm::fastAtanGTX(x.x),
            glm::fastAtanGTX(x.y),
            glm::fastAtanGTX(x.z));
    }

    template <typename T> 
    inline _xvec4<T> fastAtanGTX(const _xvec4<T>& x)
    {
        return _xvec4<T>(
            glm::fastAtanGTX(x.x),
            glm::fastAtanGTX(x.y),
            glm::fastAtanGTX(x.z),
            glm::fastAtanGTX(x.w));
    }
}

#endif//__gtx_fast_trigonometry_inl__
