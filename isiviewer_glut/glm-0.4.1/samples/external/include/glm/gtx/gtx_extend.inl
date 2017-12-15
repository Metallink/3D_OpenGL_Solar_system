//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-07
// Updated : 2006-01-07
// Licence : This source is under GNU LGPL licence
// File    : gtx_extend.inl
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_extend_inl__
#define __gtx_extend_inl__

#include "gtx_extend.h"

namespace glm
{
	template <typename T>
    T extend(const T Origin, const T Source, const T Distance)
    {
        return Origin + (Source - Origin) * Distance;
    }

	template <typename T>
    _xvec2<T> extend(const _xvec2<T>& Origin, const _xvec2<T>& Source, const T Distance)
    {
        return Origin + (Source - Origin) * Distance;
    }

	template <typename T>
    _xvec3<T> extend(const _xvec3<T>& Origin, const _xvec3<T>& Source, const T Distance)
    {
        return Origin + (Source - Origin) * Distance;
    }

	template <typename T>
    _xvec4<T> extend(const _xvec4<T>& Origin, const _xvec4<T>& Source, const T Distance)
    {
        return Origin + (Source - Origin) * Distance;
    }
}

#endif//__gtx_extend_inl__
