//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-27
// Updated : 2005-12-27
// Licence : This source is under GNU LGPL licence
// File    : gtx_matrix_access.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_matrix_access_h__
#define __gtx_matrix_access_h__

#define GLM_GTX_matrix_access 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> rowGTX(const _xmat2<T> & m, int index, const _xvec2<T>& x);
    template <typename T> _xmat3<T> rowGTX(const _xmat3<T> & m, int index, const _xvec3<T>& x);
    template <typename T> _xmat4<T> rowGTX(const _xmat4<T> & m, int index, const _xvec4<T>& x);
    template <typename T> _xmat2<T> columnGTX(const _xmat2<T> & m, int index, const _xvec2<T>& x);
    template <typename T> _xmat3<T> columnGTX(const _xmat3<T> & m, int index, const _xvec3<T>& x);
    template <typename T> _xmat4<T> columnGTX(const _xmat4<T> & m, int index, const _xvec4<T>& x);
}

#endif//__gtx_matrix_access_h__
