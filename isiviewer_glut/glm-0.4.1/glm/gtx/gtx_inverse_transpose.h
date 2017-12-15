//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-04
// Updated : 2006-01-04
// Licence : This source is under GNU LGPL licence
// File    : gtx_inverse_transpose.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_inverse_transpose_h__
#define __gtx_inverse_transpose_h__

#define GLM_GTX_inverse_transpose 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> inverseTransposeGTX(const _xmat2<T> & m);
    template <typename T> _xmat3<T> inverseTransposeGTX(const _xmat3<T> & m);
    template <typename T> _xmat4<T> inverseTransposeGTX(const _xmat4<T> & m);
}

#endif//__gtx_inverse_transpose_h__
