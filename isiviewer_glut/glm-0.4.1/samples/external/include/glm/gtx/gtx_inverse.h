//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_inverse.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_inverse_h__
#define __gtx_inverse_h__

#define GLM_GTX_inverse 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat2<T> inverseGTX(const _xmat2<T>& m);
    template <typename T> _xmat3<T> inverseGTX(const _xmat3<T>& m);
    template <typename T> _xmat4<T> inverseGTX(const _xmat4<T>& m);

    template <typename T> _xmat2<T> inverseAffinedGTX(const _xmat2<T>& m);
    template <typename T> _xmat3<T> inverseAffinedGTX(const _xmat3<T>& m);
    template <typename T> _xmat4<T> inverseAffinedGTX(const _xmat4<T>& m);
}

#endif//__gtx_inverse_h__
