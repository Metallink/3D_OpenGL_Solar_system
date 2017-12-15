//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_perpendicular.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_perpendicular_h__
#define __gtx_perpendicular_h__

#define GLM_GTX_perpendicular 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xvec2<T> perpGTX(const _xvec2<T>& x, const _xvec2<T>& Normal); //!< \brief Projects x a perpendicular axis of Normal (from GLM_GTX_perpendicular extension)
    template <typename T> _xvec3<T> perpGTX(const _xvec3<T>& x, const _xvec3<T>& Normal); //!< \brief Projects x a perpendicular axis of Normal (from GLM_GTX_perpendicular extension)
    template <typename T> _xvec4<T> perpGTX(const _xvec4<T>& x, const _xvec4<T>& Normal); //!< \brief Projects x a perpendicular axis of Normal (from GLM_GTX_perpendicular extension)
}

#endif//__gtx_perpendicular_h__
