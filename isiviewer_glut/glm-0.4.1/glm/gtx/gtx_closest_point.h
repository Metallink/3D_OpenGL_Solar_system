//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-30
// Updated : 2005-12-30
// Licence : This source is under GNU LGPL licence
// File    : gtx_closest_point.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GL_GTX_closest_point
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_closest_point_h__
#define __gtx_closest_point_h__

#define GLM_GTX_closest_point 1
#include "../glm.h"

namespace glm
{
    template <typename T> inline _xvec3<T> closestPointOnLine(const _xvec3<T>& point, const _xvec3<T>& a, const _xvec3<T>& b); //!< Finds the position on straight line (A, B) witch is the closest of point. (from GLM_GTX_closest_point extension) 
}

#endif//__gtx_closest_point_h__
