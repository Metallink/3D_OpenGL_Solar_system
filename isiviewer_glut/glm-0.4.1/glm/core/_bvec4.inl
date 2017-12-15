//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _bvec4.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __bvec4_inl__
#define __bvec4_inl__

namespace glm
{
    //////////////////////////////////////////////////////////////
    // bvec4 constructors

    inline _bvec4::_bvec4() :
        x(false),
        y(false),
        z(false),
        w(false)
    {}

    inline _bvec4::_bvec4(const _bvec4& v) :
        x(v.x),
        y(v.y),
        z(v.z),
        w(v.w)
    {}

    // Bool constructors
    inline _bvec4::_bvec4(const bool a) :
        x(a),
        y(a),
        z(a),
        w(a)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const bool c, const bool d) :
        x(a),
        y(b),
        z(c),
        w(b)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const bool c, const _bvec2& d) :
        x(a),
        y(b),
        z(c),
        w(d.x)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const bool c, const _bvec3& d) :
        x(a),
        y(b),
        z(c),
        w(d.x)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const bool c, const _bvec4& d) :
        x(a),
        y(b),
        z(c),
        w(d.x)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const _bvec2& c) :
        x(a),
        y(b),
        z(c.x),
        w(c.y)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const _bvec3& c) :
        x(a),
        y(b),
        z(c.x),
        w(c.y)
    {}

    inline _bvec4::_bvec4(const bool a, const bool b, const _bvec4& c) :
        x(a),
        y(b),
        z(c.x),
        w(c.y)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec2& b, const bool c) :
        x(a),
        y(b.x),
        z(b.y),
        w(c)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec2& b, const _bvec2& c) :
        x(a),
        y(b.x),
        z(b.y),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec2& b, const _bvec3& c) :
        x(a),
        y(b.x),
        z(b.y),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec2& b, const _bvec4& c) :
        x(a),
        y(b.x),
        z(b.y),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec3& b) :
        x(a),
        y(b.x),
        z(b.y),
        w(b.z)
    {}

    inline _bvec4::_bvec4(const bool a, const _bvec4& b) :
        x(a),
        y(b.x),
        z(b.y),
        w(b.z)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const bool b, const bool c) :
        x(a.x),
        y(a.y),
        z(b),
        w(c)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const bool b, const _bvec2& c) :
        x(a.x),
        y(a.y),
        z(b),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const bool b, const _bvec3& c) :
        x(a.x),
        y(a.y),
        z(b),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const bool b, const _bvec4& c) :
        x(a.x),
        y(a.y),
        z(b),
        w(c.x)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const _bvec2& b) :
        x(a.x),
        y(a.y),
        z(b.x),
        w(b.y)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const _bvec3& b) :
        x(a.x),
        y(a.y),
        z(b.x),
        w(b.y)
    {}

    inline _bvec4::_bvec4(const _bvec2& a, const _bvec4& b) :
        x(a.x),
        y(a.y),
        z(b.x),
        w(b.y)
    {}

    inline _bvec4::_bvec4(const _bvec3& a, const bool b) :
        x(a.x),
        y(a.y),
        z(a.z),
        w(b)
    {}

    inline _bvec4::_bvec4(const _bvec3& a, const _bvec2& b) :
        x(a.x),
        y(a.y),
        z(a.z),
        w(b.x)
    {}

    inline _bvec4::_bvec4(const _bvec3& a, const _bvec3& b) :
        x(a.x),
        y(a.y),
        z(a.z),
        w(b.x)
    {}

    inline _bvec4::_bvec4(const _bvec3& a, const _bvec4& b) :
        x(a.x),
        y(a.y),
        z(a.z),
        w(b.x)
    {}

    //////////////////////////////////////////////////////////////
    // U constructors
    template <typename U> 
    inline _bvec4::_bvec4(const U a) :
        x(bool(a)),
        y(bool(a)),
        z(bool(a)),
        w(bool(a))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const U c, const U d) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c)),
        w(bool(d))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const U c, const _xvec2<U>& d) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c)),
        w(bool(d.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const U c, const _xvec3<U>& d) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c)),
        w(bool(d.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const U c, const _xvec4<U>& d) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c)),
        w(bool(d.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const _xvec2<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x)),
        w(bool(c.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const _xvec3<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x)),
        w(bool(c.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const U b, const _xvec4<U>& c) :
        x(bool(a)),
        y(bool(b)),
        z(bool(c.x)),
        w(bool(c.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec2<U>& b, const U c) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(c))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec2<U>& b, const _xvec2<U>& c) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec2<U>& b, const _xvec3<U>& c) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec2<U>& b, const _xvec4<U>& c) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec3<U>& b) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(b.z))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const U a, const _xvec4<U>& b) :
        x(bool(a)),
        y(bool(b.x)),
        z(bool(b.y)),
        w(bool(b.z))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const U b, const U c) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b)),
        w(bool(c))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const U b, const _xvec2<U>& c) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const U b, const _xvec3<U>& c) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const U b, const _xvec4<U>& c) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b)),
        w(bool(c.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const _xvec2<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x)),
        w(bool(b.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const _xvec3<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x)),
        w(bool(b.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec2<U>& a, const _xvec4<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(b.x)),
        w(bool(b.y))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec3<U>& a, const U b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z)),
        w(bool(b))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec3<U>& a, const _xvec2<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z)),
        w(bool(b.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec3<U>& a, const _xvec3<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z)),
        w(bool(b.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec3<U>& a, const _xvec4<U>& b) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z)),
        w(bool(b.x))
    {}

    template <typename U> 
    inline _bvec4::_bvec4(const _xvec4<U>& a) :
        x(bool(a.x)),
        y(bool(a.y)),
        z(bool(a.z)),
        w(bool(a.w))
    {}

    //////////////////////////////////////////////////////////////
    // bvec4 accesses

    inline bool& _bvec4::operator[](int i)
    {
        return (&x)[i];
    }

    inline bool _bvec4::operator[](int i) const
    {
        return (&x)[i];
    }

    inline _bvec4::operator bool*()
    {
        return &x;
    }

    inline _bvec4::operator const bool*() const 
    {
        return &x;
    }

    //////////////////////////////////////////////////////////////
    // bvec4 operators

    // This function shouldn't required but it seems that VC7.1 have an optimisation bug if this operator wasn't declared
    inline _bvec4& _bvec4::operator=(const _bvec4& v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;
        return *this;
    }
/*
    inline _bvec4 _bvec4::operator--()
    {
	    this->x = !x;
	    this->y = !y;
        this->z = !z;
        this->w = !w;
	    return *this;
    }

    inline _bvec4 _bvec4::operator++()
    {
	    this->x = !x;
	    this->y = !y;
        this->z = !z;
        this->w = !w;
	    return *this;
    }

    inline const _bvec4 _bvec4::operator--(int n) const 
    {
		return _bvec4(
			!this->x, 
			!this->y, 
			!this->z, 
			!this->w);
    }

    inline const _bvec4 _bvec4::operator++(int n) const
    {
		return _bvec4(
			!this->x, 
			!this->y, 
			!this->z, 
			!this->w);
    }
*/
    inline _bvec4 _bvec4::operator!() const 
    {
		return _bvec4(
			!this->x, 
			!this->y, 
			!this->z, 
			!this->w);
    }
} //namespace glm

#endif//__bvec4_inl__
