//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-01-14
// Updated : 2006-05-17
// Licence : This source is under GNU LGPL licence
//////////////////////////////////////////////////////////////////////////////////

/*
Compiler identifier :
CC_VC71
CC_GCC3
*/

#ifndef __glm_h__
#define __glm_h__
/*
#if defined(_WINDOWS_) || defined(_WINDOWS_H)
#error windows.h included before glm.h
#endif
*/
#undef max
#undef min

#define GLM_VERSION_1_0 1

#include "./core/_xvec2.inl"
#include "./core/_xvec3.inl"
#include "./core/_xvec4.inl"
#include "./core/_bvec2.inl"
#include "./core/_bvec3.inl"
#include "./core/_bvec4.inl"
#include "./core/_xmat2.inl"
#include "./core/_xmat3.inl"
#include "./core/_xmat4.inl"
#include "./core/_func.inl"
#include "./core/_swizzle.h"

//! \brief OpenGL Mathematics namespace
namespace glm
{
    typedef _xvec2<float>   vec2;		//!< \brief Vector of 2 floating-point numbers. (From GLSL 1.10.59 specification)
    typedef _xvec2<int>     ivec2;		//!< \brief Vector of 2 integers. (From GLSL 1.10.59 specification)
    typedef _bvec2          bvec2;		//!< \brief Vector of 2 booleans. (From GLSL 1.10.59 specification)
    typedef _xvec3<float>   vec3;		//!< \brief Vector of 3 floating-point numbers. (From GLSL 1.10.59 specification)
    typedef _xvec3<int>     ivec3;		//!< \brief Vector of 3 integers. (From GLSL 1.10.59 specification)
    typedef _bvec3          bvec3;		//!< \brief Vector of 3 booleans. (From GLSL 1.10.59 specification)
    typedef _xvec4<float>   vec4;		//!< \brief Vector of 4 floating-point numbers. (From GLSL 1.10.59 specification)
    typedef _xvec4<int>     ivec4;		//!< \brief Vector of 4 integers. (From GLSL 1.10.59 specification)
    typedef _bvec4          bvec4;		//!< \brief Vector of 4 booleans. (From GLSL 1.10.59 specification)
    typedef _xmat2<float>   mat2;		//!< \brief 2 * 2 matrix of floating-point numbers. (From GLSL 1.10.59 specification)
    typedef _xmat3<float>   mat3;		//!< \brief 3 * 3 matrix of floating-point numbers. (From GLSL 1.10.59 specification)
    typedef _xmat4<float>   mat4;		//!< \brief 4 * 4 matrix of floating-point numbers. (From GLSL 1.10.59 specification)
} //namespace glm

#endif //__glm_h__
