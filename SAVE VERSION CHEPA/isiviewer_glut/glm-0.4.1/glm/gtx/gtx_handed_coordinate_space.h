//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_handed_coordinate_space.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_handed_coordinate_space_h__
#define __gtx_handed_coordinate_space_h__

#define GLM_GTX_handed_coordinate_space 1
#include "../glm.h"

namespace glm
{
    template <typename T> bool rightHandedGTX(const _xvec3<T>& tangent, const _xvec3<T>& binormal, const _xvec3<T>& normal);
    template <typename T> bool leftHandedGTX(const _xvec3<T>& tangent, const _xvec3<T>& binormal, const _xvec3<T>& normal);
}

#endif//__gtx_handed_coordinate_space_h__
