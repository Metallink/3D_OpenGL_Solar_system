//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_orthonormalize.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_orthonormalize_h__
#define __gtx_orthonormalize_h__

#define GLM_GTX_orthonormalize 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat3<T> orthonormalizeGTX(const _xmat3<T>& m); //!< \brief Returns the orthonormalized matrix of m (from GLM_GTX_orthonormalize extension)
    template <typename T> _xvec3<T> orthonormalizeGTX(const _xvec3<T>& x, const _xvec3<T>& y); //!< \brief Orthonormalizes x according y (from GLM_GTX_orthonormalize extension)
}

#endif//__gtx_orthonormalize_h__
