//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-21
// Updated : 2006-04-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_inertia.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_inertia_inl__
#define __gtx_inertia_inl__

#include "gtx_inertia.h"

namespace glm
{
    template <typename T>
    inline _xmat3<T> boxInertia3(const T Mass, const _xvec3<T>& Scale)
    {
	    _xmat3<T> Result(T(1));
	    Result[0][0] = (Scale.y * Scale.y + Scale.z * Scale.z) * Mass / T(12);
	    Result[1][1] = (Scale.x * Scale.x + Scale.z * Scale.z) * Mass / T(12);
	    Result[2][2] = (Scale.x * Scale.x + Scale.y * Scale.y) * Mass / T(12);
        return Result;
    }

    template <typename T>
    inline _xmat4<T> boxInertia4(const T Mass, const _xvec3<T>& Scale)
    {
	    _xmat4<T> Result(T(1));
	    Result[0][0] = (Scale.y * Scale.y + Scale.z * Scale.z) * Mass / T(12);
	    Result[1][1] = (Scale.x * Scale.x + Scale.z * Scale.z) * Mass / T(12);
	    Result[2][2] = (Scale.x * Scale.x + Scale.y * Scale.y) * Mass / T(12);
        return Result;
    }

    template <typename T>
    inline _xmat3<T> diskInertia3(const T Mass, const T Radius)
    {
        T a = Mass * Radius * Radius / T(2);
        _xmat3<T> Result(a);
        Result[2][2] *= T(2);
        return Result;
    }

    template <typename T>
    inline _xmat4<T> diskInertia4(const T Mass, const T Radius)
    {
        T a = Mass * Radius * Radius / T(2);
        _xmat4<T> Result(a);
        Result[2][2] *= T(2);
        Result[3][3] = T(1);
        return Result;
    }

    template <typename T>
    inline _xmat3<T> ballInertia3(const T Mass, const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(5);
        return _xmat3<T>(a);
    }

    template <typename T>
    inline _xmat4<T> ballInertia4(const T Mass, const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(5);
        _xmat4<T> Result(a);
        Result[3][3] = T(1);
        return Result;
    }

    template <typename T>
    inline _xmat3<T> sphereInertia3(const T Mass, const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(3);
        return _xmat3<T>(a);
    }

    template <typename T>
    inline _xmat4<T> sphereInertia4(const T Mass, const T Radius)
    {
        T a = T(2) * Mass * Radius * Radius / T(3);
        _xmat4<T> Result(a);
        Result[3][3] = T(1);
        return Result;
    }
}

#endif//__gtx_inertia_inl__
