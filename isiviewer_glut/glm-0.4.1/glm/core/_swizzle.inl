//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _swizzle.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __swizzle_inl__
#define __swizzle_inl__

#include "./_swizzle.h"

namespace glm
{
    // _xref2
    template <typename T>
    _xref2<T>::_xref2(T& x, T& y) :
        x(x),
        y(y)
    {}

    template <typename T>
    _xref2<T>& _xref2<T>::operator=(const _xvec2<T>& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    template <typename T>
    _xref2<T>& _xref2<T>::operator=(const _xref2& r)
    {
        x = r.x;
        y = r.y;
        return *this;
    }

    // _xref3
    template <typename T>
    _xref3<T>::_xref3(T& x, T& y, T& z) :
        x(x),
        y(y),
        z(z)
    {}

    template <typename T>
    _xref3<T>& _xref3<T>::operator=(const _xvec3<T>& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    template <typename T>
    _xref3<T>& _xref3<T>::operator=(const _xref3& r)
    {
        x = r.x;
        y = r.y;
        z = r.z;
        return *this;
    }

    // _xref4
    template <typename T>
    _xref4<T>::_xref4(T& x, T& y, T& z, T& w) :
        x(x),
        y(y),
        z(z),
        w(w)
    {}

    template <typename T>
    _xref4<T>& _xref4<T>::operator=(const _xvec4<T>& v)
    {
        x = v.x;
        y = v.y;
        z = v.z;
        w = v.w;
        return *this;
    }

    template <typename T>
    _xref4<T>& _xref4<T>::operator=(const _xref4& r)
    {
        x = r.x;
        y = r.y;
        z = r.z;
        w = r.w;
        return *this;
    }
}

#endif//__swizzle_inl__
