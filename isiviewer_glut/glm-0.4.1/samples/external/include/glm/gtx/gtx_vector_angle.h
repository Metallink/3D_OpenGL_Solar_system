//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-30
// Updated : 2005-12-30
// Licence : This source is under GNU LGPL licence
// File    : gtx_vector_angle.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GL_GTX_vector_angles
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_vector_angle_h__
#define __gtx_vector_angle_h__

#define GLM_GTX_vector_angle 1
#include "../glm.h"

namespace glm
{
    template <typename T> T angleGTX(T x, T y); //!< Returns the absolute angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T angleGTX(const _xvec2<T>& x, const _xvec2<T>& y); //!< Returns the absolute angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T angleGTX(const _xvec3<T>& x, const _xvec3<T>& y); //!< Returns the absolute angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T angleGTX(const _xvec4<T>& x, const _xvec4<T>& y); //!< Returns the absolute angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T orientedAngleGTX(const _xvec2<T>& x, const _xvec2<T>& y); //!< Returns the oriented angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T orientedAngleGTX(const _xvec3<T>& x, const _xvec3<T>& y); //!< Returns the oriented angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> T orientedAngleGTX(const _xvec4<T>& x, const _xvec4<T>& y); //!< Returns the oriented angle between x and y (From GLM_GTX_vector_angle extension)
    template <typename T> _xvec3<T> rotateGTX(const _xvec3<T>& x, T degrees, const _xvec3<T>& normal); //!< Returns a degrees rotated vector from x around normal (From GLM_GTX_vector_angle extension)
}

#endif//__gtx_vector_angle_h__
