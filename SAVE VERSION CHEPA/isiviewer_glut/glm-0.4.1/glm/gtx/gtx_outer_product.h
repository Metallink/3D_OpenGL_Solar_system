//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2006 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-03-30
// Updated : 2006-03-30
// Licence : This source is under GNU LGPL licence
// File    : gtx_outer_product.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_outer_product_h__
#define __gtx_outer_product_h__

#define GLM_GTX_outer_product 1
#include "../glm.h"

namespace glm
{
	template <typename T> _xmat2<T> outerProductGTX(const _xvec2<T>& x, const _xvec2<T>& y); //! Product of x extended to a matrix with the y extended to a transposed matrix
    template <typename T> _xmat3<T> outerProductGTX(const _xvec3<T>& x, const _xvec3<T>& y); //! Product of x extended to a matrix with the y extended to a transposed matrix
    template <typename T> _xmat4<T> outerProductGTX(const _xvec4<T>& x, const _xvec4<T>& y); //! Product of x extended to a matrix with the y extended to a transposed matrix
}

#endif//__gtx_outer_product_h__
