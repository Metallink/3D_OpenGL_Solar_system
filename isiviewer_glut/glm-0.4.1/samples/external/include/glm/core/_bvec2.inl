//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _bvec2.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __bvec2_inl__
#define __bvec2_inl__

#include "./_bvec2.h"
#include "./_bvec3.h"
#include "./_bvec4.h"

namespace glm
{
    //////////////////////////////////////////////////////////////
    // Common constructors

    inline _bvec2::_bvec2() :
        x(false),
        y(false)
    {}

    inline _bvec2::_bvec2(const _bvec2& v) :
        x(v.x),
        y(v.y)
    {}

    //////////////////////////////////////////////////////////////
    // Bool constructors

    inline _bvec2::_bvec2(const bool a) :
        x(a),
        y(a)
    {}

    inline _bvec2::_bvec2(const bool a, const bool b) :
        x(a),
        y(b)
    {}

    inline _bvec2::_bvec2(const bool a, const _bvec2& b) :
        x(a),
        y(b.x)
    {}

    inline _bvec2::_bvec2(const bool a, const _bvec3& b) :
        x(a),
        y(b.x)
    {}

    inline _bvec2::_bvec2(const bool a, const _bvec4& b) :
        x(a),
        y(b.x)
    {}

    inline _bvec2::_bvec2(const _bvec3& a) :
        x(a.x),
        y(a.y)
    {}

    inline _bvec2::_bvec2(const _bvec4& a) :
        x(a.x),
        y(a.y)
    {}

    //////////////////////////////////////////////////////////////
    // U constructors

    template <typename U> 
    inline _bvec2::_bvec2(const U a) :
        x(bool(a)),
        y(bool(a))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const U a, const U b) :
        x(bool(a)),
        y(bool(b))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const U a, const _xvec2<U>& b) :
        x(bool(a)),
        y(bool(b.x))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const U a, const _xvec3<U>& b) :
        x(bool(a)),
        y(bool(b.x))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const U a, const _xvec4<U>& b) :
        x(bool(a)),
        y(bool(b.x))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const _xvec3<U>& a) :
        x(bool(a.x)),
        y(bool(a.y))
    {}

    template <typename U> 
    inline _bvec2::_bvec2(const _xvec4<U>& a) :
        x(bool(a.x)),
        y(bool(a.y))
    {}

    //////////////////////////////////////////////////////////////
    // bvec2 accesses

    inline bool& _bvec2::operator[](int i)
    {
        return (&x)[i];
    }

    inline bool _bvec2::operator[](int i) const
    {
        return (&x)[i];
    }

    inline _bvec2::operator bool*()
    {
        return &x;
    }

    inline _bvec2::operator const bool*() const 
    {
        return &x;
    }

    //////////////////////////////////////////////////////////////
    // bvec2 operators

    // This function shouldn't required but it seems that VC7.1 have an optimisation bug if this operator wasn't declared
    inline _bvec2& _bvec2::operator=(const _bvec2& x)
    {
        this->x = x.x;
        this->y = x.y;
        return *this;
    }
/*
    inline _bvec2 _bvec2::operator--()
    {
	    x = !x;
	    y = !y;
	    return *this;
    }

    inline _bvec2 _bvec2::operator++()
    {
	    x = !x;
	    y = !y;
	    return *this;
    }

    inline const _bvec2 _bvec2::operator--(int n) const 
    {
        return _bvec2(
			!this->x, 
			!this->y);
    }

    inline const _bvec2 _bvec2::operator++(int n) const
    {
	    return _bvec2(
			!this->x, 
			!this->y);
    }
*/
    inline _bvec2 _bvec2::operator!() const 
    {
	    return _bvec2(
			!this->x, 
			!this->y);
    }
} //namespace glm

#endif //__bvec2_inl__
