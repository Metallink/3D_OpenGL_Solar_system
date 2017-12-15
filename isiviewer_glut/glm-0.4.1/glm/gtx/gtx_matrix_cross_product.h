//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_matrix_cross_product.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_matrix_cross_product_h__
#define __gtx_matrix_cross_product_h__

#define GLM_GTX_matrix_cross_product 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat3<T> matrixCross3GTX(const _xvec3<T>& x);
    template <typename T> _xmat4<T> matrixCross4GTX(const _xvec3<T>& x);
}

#endif//__gtx_matrix_cross_product_h__
