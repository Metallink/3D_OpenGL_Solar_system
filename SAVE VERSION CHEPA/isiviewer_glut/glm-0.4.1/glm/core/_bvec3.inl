//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _bvec3.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __bvec3_inl__
#define __bvec3_inl__

namespace glm
{
    //////////////////////////////////////////////////////////////
    // Common constructors

    inline _bvec3::_bvec3() :
        x(false),
        y(false),
        z(false)
    {}

    inline _bvec3::_bvec3(const _bvec3& v) : 
        x(v.x),
        y(v.y),
        z(v.z)
    {}

    //////////////////////////////////////////////////////////////
    // Bool constructors

    inline _bvec3::_bvec3(const bool a) :
        x(a),
        y(a),
        z(a)
    {}

    inline _bvec3::_bvec3(const bool a, const bool b, const bool c) :
        x(a),
        y(b),
        z(c)
    {}

    inline _bvec3::_bvec3(const bool a, const bool b, const _bvec2& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    inline _bvec3::_bvec3(const bool a, const bool b, const _bvec3& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    inline _bvec3::_bvec3(const bool a, const bool b, const _bvec4& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    inline _bvec3::_bvec3(const bool a, const _bvec2& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    inline _bvec3::_bvec3(const bool a, const _bvec3& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    inline _bvec3::_bvec3(const bool a, const _bvec4& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    inline _bvec3::_bvec3(const _bvec2& a, bool b) :
        x(a.x),
        y(a.y),
        z(b)
    {}

    inline _bvec3::_bvec3(const _bvec2& a, const _bvec2& b) :
        x(a.x),
        y(a.y),
        z(b.x)
    {}

    inline _bvec3::_bvec3(const _bvec2& a, const _bvec3& b) :
        x(a.x),
        y(a.y),
        z(b.x)
    {}

    inline _bvec3::_bvec3(const _bvec2& a, const _bvec4& b) :
        x(a.x),
        y(a.y),
        z(b.x)
    {}

    inline _bvec3::_bvec3(const _bvec4& a) :
        x(a.x),
        y(a.y),
        z(a.z)
    {}

    //////////////////////////////////////////////////////////////
    // U constructors

    template <typename U> 
    inline _bvec3::_bvec3(const U a) :
        x(bool(a)),
        y(bool(a)),
        z(bool(a))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const U b, const U c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const U b, const _xvec2<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const U b, const _xvec3<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const U b, const _xvec4<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const _xvec2<U>& b) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const _xvec3<U>& b) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const U a, const _xvec4<U>& b) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec2<U>& a, U b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec2<U>& a, const _xvec2<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec2<U>& a, const _xvec3<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec2<U>& a, const _xvec4<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec3<U>& a) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z))
    {}

    template <typename U> 
    inline _bvec3::_bvec3(const _xvec4<U>& a) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z))
    {}

    //////////////////////////////////////////////////////////////
    // bvec3 accesses

    inline bool& _bvec3::operator [] (int i)
    {
        return (&x)[i];
    }

    inline bool _bvec3::operator [] (int i) const
    {
        return (&x)[i];
    }

    inline _bvec3::operator bool* ()
    {
        return &x;
    }

    inline _bvec3::operator const bool* () const 
    {
        return &x;
    }

    //////////////////////////////////////////////////////////////
    // bvec3 operators

    // This function shouldn't required but it seems that VC7.1 have an optimisation bug if this operator wasn't declared
    inline _bvec3& _bvec3::operator=(const _bvec3& x)
    {
        this->x = x.x;
        this->y = x.y;
        this->z = x.z;
        return *this;
    }
/*
    inline _bvec3 _bvec3::operator--()
    {
	    this->x = !x;
	    this->y = !y;
        this->z = !z;
	    return *this;
    }

    inline _bvec3 _bvec3::operator++()
    {
	    this->x = !x;
	    this->y = !y;
        this->z = !z;
	    return *this;
    }

    inline const _bvec3 _bvec3::operator--(int n) const 
    {
		return _bvec3(
			!this->x, 
			!this->y, 
			!this->z);
    }

    inline const _bvec3 _bvec3::operator++(int n) const
    {
		return _bvec3(
			!this->x, 
			!this->y, 
			!this->z);
    }
*/
    inline _bvec3 _bvec3::operator!() const 
    {
		return _bvec3(
			!this->x, 
			!this->y, 
			!this->z);
    }
} //namespace glm

#endif//__bvec3_inl__
