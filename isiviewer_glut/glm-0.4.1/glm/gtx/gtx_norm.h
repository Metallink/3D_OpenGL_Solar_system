//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_norm.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GLM_GTX_quaternion
// - GLM_GTX_double
//////////////////////////////////////////////////////////////////////////////////
// ToDo:
// - Study the validity of the notion of length2 to quaternion
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_norm_h__
#define __gtx_norm_h__

#define GLM_GTX_norm 1
#include "../glm.h"
#include "gtx_quaternion.h"

namespace glm
{
    template <typename T> T length2GTX(const T x); //!< \brief Returns the squared length of x (from GLM_GTX_norm extension)
    template <typename T> T length2GTX(const _xvec2<T>& x); //!< \brief Returns the squared length of x (from GLM_GTX_norm extension)
    template <typename T> T length2GTX(const _xvec3<T>& x); //!< \brief Returns the squared length of x (from GLM_GTX_norm extension)
    template <typename T> T length2GTX(const _xvec4<T>& x); //!< \brief Returns the squared length of x (from GLM_GTX_norm extension)
    template <typename T> T length2GTX(const _xquat<T>& q); //!< \brief Returns the squared length of x (from GLM_GTX_norm extension)
    template <typename T> T l1NormGTX(const _xvec3<T>& x, const _xvec3<T>& y); //!< \brief Returns the L1 norm between x and y (from GLM_GTX_norm extension)
}

#endif//__gtx_norm_h__
