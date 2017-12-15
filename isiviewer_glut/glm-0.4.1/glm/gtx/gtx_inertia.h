//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-21
// Updated : 2006-04-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_inertia.h
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_inertia_h__
#define __gtx_inertia_h__

#define GLM_GTX_inertia 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat3<T> boxInertia3(const T Mass, const _xvec3<T>& Scale);
    template <typename T> _xmat4<T> boxInertia4(const T Mass, const _xvec3<T>& Scale);
    template <typename T> _xmat3<T> diskInertia3(const T Mass, const T Radius);
    template <typename T> _xmat4<T> diskInertia4(const T Mass, const T Radius);
    template <typename T> _xmat3<T> ballInertia3(const T Mass, const T Radius);
    template <typename T> _xmat4<T> ballInertia4(const T Mass, const T Radius);
    template <typename T> _xmat3<T> sphereInertia3(const T Mass, const T Radius);
    template <typename T> _xmat4<T> sphereInertia4(const T Mass, const T Radius);
}

#endif//__gtx_inertia_h__
