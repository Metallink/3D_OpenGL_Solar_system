//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_transpose.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_transpose_h__
#define __gtx_transpose_h__

#define GLM_GTX_transpose 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> transposeGTX(const _xmat2<T>& x); //!< Returns the transposed 2 * 2 matrix of x (From GLM_GTX_transpose extension)
    template <typename T> _xmat3<T> transposeGTX(const _xmat3<T>& x); //!< Returns the transposed 3 * 3 matrix of x (From GLM_GTX_transpose extension)
    template <typename T> _xmat4<T> transposeGTX(const _xmat4<T>& x); //!< Returns the transposed 4 * 4 matrix of x (From GLM_GTX_transpose extension)
}

#endif//__gtx_transpose_h__
