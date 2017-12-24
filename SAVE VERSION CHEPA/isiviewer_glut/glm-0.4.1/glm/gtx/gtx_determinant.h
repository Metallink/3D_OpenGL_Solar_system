//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_determinant.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_determinant_h__
#define __gtx_determinant_h__

#define GLM_GTX_determinant 1
#include "../glm.h"

namespace glm
{
    template <typename T> T determinantGTX(const _xmat2<T>& m); //!< \brief Returns the determinant of a 2 * 2 matrix. (From GLM_GTX_determinant extension)
    template <typename T> T determinantGTX(const _xmat3<T>& m); //!< \brief Returns the determinant of a 3 * 3 matrix. (From GLM_GTX_determinant extension)
    template <typename T> T determinantGTX(const _xmat4<T>& m); //!< \brief Returns the determinant of a 4 * 4 matrix. (From GLM_GTX_determinant extension)
}

#endif//__gtx_determinant_h__
