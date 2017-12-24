//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_normal.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_normal_h__
#define __gtx_normal_h__

#define GLM_GTX_normal 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xvec3<T> triangleNormalGTX(const _xvec3<T>& p1, const _xvec3<T>& p2, const _xvec3<T>& p3); //!< /brief Computes triangle normal from triangle points. (from GLM_GTX_normal extension)
}

#endif//__gtx_normal_h__
