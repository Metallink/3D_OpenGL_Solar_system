//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-19
// Updated : 2006-04-19
// Licence : This source is under GNU LGPL licence
// File    : gtx_matrix_major_storage.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_matrix_major_storage_h__
#define __gtx_matrix_major_storage_h__

#define GLM_GTX_matrix_major_storage 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> rowMajor2(const _xvec2<T>& v1, const _xvec2<T>& v2);
    template <typename T> _xmat2<T> rowMajor2(const _xmat2<T>& m);
    template <typename T> _xmat3<T> rowMajor3(const _xvec3<T>& v1, const _xvec3<T>& v2, const _xvec3<T>& v3);
    template <typename T> _xmat3<T> rowMajor3(const _xmat3<T>& m);
    template <typename T> _xmat4<T> rowMajor4(const _xvec4<T>& v1, const _xvec4<T>& v2, const _xvec4<T>& v3, const _xvec4<T>& v4);
    template <typename T> _xmat4<T> rowMajor4(const _xmat4<T>& m);

    template <typename T> _xmat2<T> colMajor2(const _xvec2<T>& v1, const _xvec2<T>& v2);
    template <typename T> _xmat2<T> colMajor2(const _xmat2<T>& m);
    template <typename T> _xmat3<T> colMajor3(const _xvec3<T>& v1, const _xvec3<T>& v2, const _xvec3<T>& v3);
    template <typename T> _xmat3<T> colMajor3(const _xmat3<T>& m);
    template <typename T> _xmat4<T> colMajor4(const _xvec4<T>& v1, const _xvec4<T>& v2, const _xvec4<T>& v3, const _xvec4<T>& v4);
    template <typename T> _xmat4<T> colMajor4(const _xmat4<T>& m);
}

#endif//__gtx_matrix_major_storage_h__
