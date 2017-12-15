//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_color_space.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_color_space_h__
#define __gtx_color_space_h__

#define GLM_GTX_color_space 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xvec3<T> rgbGTX(const _xvec3<T>& hsv); //!< \brief Converts a color from HSV color space to its color in RGB color space (from GLM_GTX_color_space extension)
    template <typename T> _xvec3<T> hsvGTX(const _xvec3<T>& rgb); //!< \brief Converts a color from RGB color space to its color in HSV color space (from GLM_GTX_color_space extension)
}

#endif//__gtx_color_space_h__
