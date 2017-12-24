//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_double.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////
// ToDo:
// - Finish to declare extension functions
// - Nothing define
// - Study extension dependencies
//////////////////////////////////////////////////////////////////////////////////
// Note:
// - This implementation doesn't need to redefine all build-in functions to
// support double based type.
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_double_h__
#define __gtx_double_h__

#define GLM_GTX_double 1
#include "../glm.h"
#include "gtx_quaternion.h"

namespace glm
{
    typedef _xvec2<float> __fvec2GTX;	//!< \brief Vector of 2 single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xvec3<float> __fvec3GTX;	//!< \brief Vector of 3 single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xvec4<float> __fvec4GTX;	//!< \brief Vector of 4 single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat2<float> __fmat2GTX;	//!< \brief 2 * 2 matrix of single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat3<float> __fmat3GTX;	//!< \brief 3 * 3 matrix of single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat4<float> __fmat4GTX;	//!< \brief 4 * 4 matrix of single-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xquat<float> __fquatGTX;	//!< \brief quaternion of single-precision floating-point numbers. (from GLM_GTX_double extension)

    typedef _xvec2<double> __dvec2GTX;	//!< \brief Vector of 2 double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xvec3<double> __dvec3GTX;	//!< \brief Vector of 3 double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xvec4<double> __dvec4GTX;	//!< \brief Vector of 4 double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat2<double> __dmat2GTX;	//!< \brief 2 * 2 matrix of double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat3<double> __dmat3GTX;	//!< \brief 3 * 3 matrix of double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xmat4<double> __dmat4GTX;	//!< \brief 4 * 4 matrix of double-precision floating-point numbers. (from GLM_GTX_double extension)
    typedef _xquat<double> __dquatGTX;	//!< \brief quaternion of double-precision floating-point numbers. (from GLM_GTX_double extension)
}

#endif//__gtx_double_h__
