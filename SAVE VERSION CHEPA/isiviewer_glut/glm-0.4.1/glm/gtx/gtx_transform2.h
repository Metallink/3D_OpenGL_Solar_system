//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_transform2.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_transform2_h__
#define __gtx_transform2_h__

//#define GLM_GTX_transform2 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat3<T> shearX2DGTX(const _xmat3<T> & m, T y);
    template <typename T> _xmat3<T> shearY2DGTX(const _xmat3<T> & m, T x);
    template <typename T> _xmat4<T> shearX3DGTX(const _xmat4<T> & m, T y, T z);
    template <typename T> _xmat4<T> shearY3DGTX(const _xmat4<T> & m, T x, T z);
    template <typename T> _xmat4<T> shearZ3DGTX(const _xmat4<T> & m, T x, T y);
    //template <typename T> _xmat4<T> shearGTX(const _xmat4<T> & m, shearPlane, planePoint, angle)
    // Identity + tan(angle) * cross(Normal, OnPlaneVector)     0
    // - dot(PointOnPlane, normal) * OnPlaneVector              1

    // Reflect functions seem to don't work
    template <typename T> _xmat3<T> reflect2DGTX(const _xmat3<T> & m, const _xvec3<T>& normal);
    template <typename T> _xmat4<T> reflect3DGTX(const _xmat4<T> & m, const _xvec3<T>& normal);
    template <typename T> _xmat3<T> proj2DGTX(const _xmat3<T> & m, const _xvec3<T>& normal);
    template <typename T> _xmat4<T> proj3DGTX(const _xmat4<T> & m, const _xvec3<T>& normal);
    template <typename T> _xmat4<T> lookAtGTX(const _xvec3<T>& eye, const _xvec3<T>& center, const _xvec3<T>& up);
}

#endif//__gtx_transform2_h__
