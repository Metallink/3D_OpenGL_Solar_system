//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-20
// Updated : 2006-04-20
// Licence : This source is under GNU LGPL licence
// File    : gtx_mul.h
//////////////////////////////////////////////////////////////////////////////////
// Commet:
// - Extension for Cg compatibility
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_mul_h__
#define __gtx_mul_h__

#define GLM_GTX_mul 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> mulGTX(const _xmat2<T>& a, const _xmat2<T>& b);
    template <typename T> _xmat3<T> mulGTX(const _xmat3<T>& a, const _xmat3<T>& b);
    template <typename T> _xmat4<T> mulGTX(const _xmat4<T>& a, const _xmat4<T>& b);

    template <typename T> _xvec2<T> mulGTX(const _xmat2<T>& m, const _xvec2<T>& v);
    template <typename T> _xvec3<T> mulGTX(const _xmat3<T>& m, const _xvec3<T>& v);
    template <typename T> _xvec4<T> mulGTX(const _xmat4<T>& m, const _xvec4<T>& v);

    template <typename T> _xvec2<T> mulGTX(const _xvec2<T>& v, const _xmat2<T>& m);
    template <typename T> _xvec3<T> mulGTX(const _xvec3<T>& v, const _xmat3<T>& m);
    template <typename T> _xvec4<T> mulGTX(const _xvec4<T>& v, const _xmat4<T>& m);
}

#endif//__gtx_mul_h__
