//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-04-27
// Updated : 2006-04-27
// Licence : This source is under GNU LGPL licence
// File    : _xvec3.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __xvec3_inl__
#define __xvec3_inl__

namespace glm
{
    // Common constructors
    template <typename T> 
    inline _xvec3<T>::_xvec3() :
        x(T(0)),
        y(T(0)),
        z(T(0))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec3<T>& v) :
        x(v.x),
        y(v.y),
        z(v.z)
    {}

    // T constructors
    template <typename T> 
    inline _xvec3<T>::_xvec3(const T x) :
        x(x),
        y(x),
        z(x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const T b, const T c) :
        x(a),
        y(b),
        z(c)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const T b, const _xvec2<T>& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const T b, const _xvec3<T>& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const T b, const _xvec4<T>& c) :
        x(a),
        y(b),
        z(c.x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const _xvec2<T>& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const _xvec3<T>& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T a, const _xvec4<T>& b) :
        x(a),
        y(b.x),
        z(b.y)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec2<T>& a, T b) :
        x(a.x),
        y(a.y),
        z(b)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec2<T>& a, const _xvec2<T>& b) :
        x(),
        y(),
        z()
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec2<T>& a, const _xvec3<T>& b) :
        x(a.x),
        y(a.y),
        z(b.x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec2<T>& a, const _xvec4<T>& b) :
        x(a.x),
        y(a.y),
        z(b.x)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec4<T>& a) :
        x(a.x),
        y(a.y),
        z(a.z)
    {}

    // U constructors
    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U x) :
        x(T(x)),
        y(T(x)),
        z(T(x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const U b, const U c) :
        x(T(a)),
        y(T(b)),
        z(T(c))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const U b, const _xvec2<U>& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const U b, const _xvec3<U>& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const U b, const _xvec4<U>& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const _xvec2<U>& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const _xvec3<U>& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const U a, const _xvec4<U>& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec2<U>& a, U b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec2<U>& a, const _xvec2<U>& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec2<U>& a, const _xvec3<U>& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec2<U>& a, const _xvec4<U>& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec3<U>& a) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(a.z))
    {}

    template <typename T> 
    template <typename U> 
    inline _xvec3<T>::_xvec3(const _xvec4<U>& a) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(a.z))
    {}

    // Bool constructors
    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool x) :
        x(T(x)),
        y(T(x)),
        z(T(x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const bool b, const bool c) :
        x(T(a)),
        y(T(b)),
        z(T(c))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const bool b, const _bvec2& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const bool b, const _bvec3& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const bool b, const _bvec4& c) :
        x(T(a)),
        y(T(b)),
        z(T(c.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const _bvec2& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const _bvec3& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const bool a, const _bvec4& b) :
        x(T(a)),
        y(T(b.x)),
        z(T(b.y))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec2& a, bool b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec2& a, const _bvec2& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec2& a, const _bvec3& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec2& a, const _bvec4& b) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(b.x))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec3& a) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(a.z))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec4& a) :
        x(T(a.x)),
        y(T(a.y)),
        z(T(a.z))
    {}

/*
    //////////////////////////////////////////////////////////////
    // vec3 and ivec3 constructors

    template <typename T> 
    inline _xvec3<T>::_xvec3() :
        x(0),
        y(0),
        z(0)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(T f) :
        x(f),
        y(f),
        z(f)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const T _x, const T _y, const T _z) :
        x(_x),
        y(_y),
        z(_z)
    {}

    //////////////////////////////////////////////////////////////
    // vec3 and ivec3 conversions

    template <typename T>
    template <typename U> 
    inline _xvec3<T>::_xvec3(U x, U y, U z) :
        x(T(x)),
        y(T(y)),
        z(T(z))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _xvec2<T>& v1, T v2) :
        x(v1.x),
        y(v1.y),
        z(v2)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(T v1, const _xvec2<T>& v2) :
        x(v1),
        y(v2.x),
        z(v2.y)
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec3& v) :
        x(T(v.x)),
        y(T(v.y)),
        z(T(v.z))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(const _bvec2& v1, bool v2) :
        x(T(v1.x)),
        y(T(v1.y)),
        z(T(v2))
    {}

    template <typename T> 
    inline _xvec3<T>::_xvec3(bool v1, const _bvec2& v2) :
        x(T(v1)),
        y(T(v2.x)),
        z(T(v2.y))
    {}

    template <typename T>
    template <typename U>
    inline _xvec3<T>::_xvec3(const _xvec3<U>& v) :
        x(T(v.x)),
        y(T(v.y)),
        z(T(v.z))
    {}

    template <typename T>
    template <typename U>
    inline _xvec3<T>::_xvec3(const _xvec2<U>& v1, U v2) :
        x(T(v1.x)),
        y(T(v1.y)),
        z(T(v2))
    {}

    template <typename T>
    template <typename U>
    inline _xvec3<T>::_xvec3(U v1, const _xvec2<U>& v2) :
        x(T(v1)),
        y(T(v2.x)),
        z(T(v2.y))
    {}

    template <typename T>
    template <typename U>
    inline _xvec3<T>::_xvec3(const _xvec4<U>& v) :
        x(T(v.x)),
        y(T(v.y)),
        z(T(v.z))
    {}
*/
    //////////////////////////////////////////////////////////////
    // vec3 and ivec3 accesses

    template <typename T> 
    inline T& _xvec3<T>::operator [] (int i)
    {
        return (&x)[i];
    }

    template <typename T> 
    inline T _xvec3<T>::operator [] (int i) const
    {
        return (&x)[i];
    }

    template <typename T> 
    inline _xvec3<T>::operator T* ()
    {
        return &x;
    }

    template <typename T> 
    inline _xvec3<T>::operator const T* () const 
    {
        return &x;
    }

    //////////////////////////////////////////////////////////////
    // vec3 and ivec3 operators

    // This function shouldn't required but it seems that VC7.1 have an optimisation bug if this operator wasn't declared
    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator=(const _xvec3<T>& v)
    {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator+= (const T s)
    {
	    this->x += s;
	    this->y += s;
        this->z += s;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator+= (const _xvec3<T>& v)
    {
	    this->x += v.x;
	    this->y += v.y;
        this->z += v.z;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator-= (const T s)
    {
	    this->x -= s;
	    this->y -= s;
        this->z -= s;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator-= (const _xvec3<T>& v)
    {
	    this->x -= v.x;
	    this->y -= v.y;
        this->z -= v.z;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator*= (const T s)
    {
	    this->x *= s;
	    this->y *= s;
        this->z *= s;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator*= (const _xvec3<T>& v)
    {
	    this->x *= v.x;
	    this->y *= v.y;
        this->z *= v.z;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator/= (const T s)
    {
	    this->x /= s;
	    this->y /= s;
        this->z /= s;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator/= (const _xvec3<T>& v)
    {
	    this->x /= v.x;
	    this->y /= v.y;
        this->z /= v.z;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator++ ()
    {
	    this->x++;
	    this->y++;
        this->z++;
	    return *this;
    }

    template <typename T> 
    inline _xvec3<T>& _xvec3<T>::operator-- ()
    {
	    this->x--;
	    this->y--;
        this->z--;
	    return *this;
    }

    // Unary constant operators
    template <typename T> 
    inline const _xvec3<T> operator- (const _xvec3<T>& v)
    {
        return _xvec3<T>(
            -v.x, 
            -v.y,
            -v.z);
    }

    template <typename T> 
    inline const _xvec3<T> operator++ (const _xvec3<T>& v, int)
    {
        return _xvec3<T>(
            v.x + T(1), 
            v.y + T(1),
            v.z + T(1));
    }

    template <typename T> 
    inline const _xvec3<T> operator-- (const _xvec3<T>& v, int)
    {
        return _xvec3<T>(
            v.x - T(1), 
            v.y - T(1),
            v.z - T(1));
    }

    // Binary operators
    template <typename T> 
    inline _xvec3<T> operator+ (const _xvec3<T>& v, const T s)
    {
	    return _xvec3<T>(
		    v.x + s,
		    v.y + s,
            v.z + s);
    }

    template <typename T> 
    inline _xvec3<T> operator+ (const T s, const _xvec3<T>& v)
    {
	    return _xvec3<T>(
		    s + v.x,
		    s + v.y,
            s + v.z);
    }

    template <typename T> 
    inline _xvec3<T> operator+ (const _xvec3<T>& v1, const _xvec3<T>& v2)
    {
	    return _xvec3<T>(
		    v1.x + v2.x,
		    v1.y + v2.y,
            v1.z + v2.z);
    }

    template <typename T> 
    inline _xvec3<T> operator- (const _xvec3<T>& v, const T s)
    {
	    return _xvec3<T>(
		    v.x - s,
		    v.y - s,
            v.z - s);
    }

    template <typename T> 
    inline _xvec3<T> operator- (const T s, const _xvec3<T>& v)
    {
	    return _xvec3<T>(
		    s - v.x,
		    s - v.y,
            s - v.z);
    }

    template <typename T> 
    inline _xvec3<T> operator- (const _xvec3<T>& v1, const _xvec3<T>& v2)
    {
	    return _xvec3<T>(
		    v1.x - v2.x,
		    v1.y - v2.y,
            v1.z - v2.z);
    }

    template <typename T> 
    inline _xvec3<T> operator* (const _xvec3<T>& v, const T s)
    {
	    return _xvec3<T>(
		    v.x * s,
		    v.y * s,
            v.z * s);
    }

    template <typename T> 
    inline _xvec3<T> operator* (const T s, const _xvec3<T>& v)
    {
	    return _xvec3<T>(
		    s * v.x,
		    s * v.y,
            s * v.z);
    }

    template <typename T> 
    inline _xvec3<T> operator* (const _xvec3<T>& v1, const _xvec3<T> & v2)
    {
	    return _xvec3<T>(
		    v1.x * v2.x,
		    v1.y * v2.y,
            v1.z * v2.z);
    }

    template <typename T> 
    inline _xvec3<T> operator/ (const _xvec3<T>& v, const T s)
    {
	    return _xvec3<T>(
		    v.x / s,
		    v.y / s,
            v.z / s);
    }

    template <typename T> 
    inline _xvec3<T> operator/ (const T s, const _xvec3<T>& v)
    {
	    return _xvec3<T>(
		    s / v.x,
		    s / v.y,
            s / v.z);
    }

    template <typename T> 
    inline _xvec3<T> operator/ (const _xvec3<T>& v1, const _xvec3<T>& v2)
    {
	    return _xvec3<T>(
		    v1.x / v2.x,
		    v1.y / v2.y,
            v1.z / v2.z);
    }

    //////////////////////////////////////////////////////////////
    // 2 components swizzles operators

    template <typename T>
    _xvec2<T> _xvec3<T>::_xx() const
    {
        return _xvec2<T>(this->x, this->x);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_yx() const
    {
        return _xvec2<T>(this->y, this->x);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_zx() const
    {
        return _xvec2<T>(this->z, this->x);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_xy() const
    {
        return _xvec2<T>(this->x, this->y);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_yy() const
    {
        return _xvec2<T>(this->y, this->y);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_zy() const
    {
        return _xvec2<T>(this->z, this->y);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_xz() const
    {
        return _xvec2<T>(this->x, this->z);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_yz() const
    {
        return _xvec2<T>(this->y, this->z);
    }

    template <typename T>
    _xvec2<T> _xvec3<T>::_zz() const
    {
        return _xvec2<T>(this->z, this->z);
    }

    //////////////////////////////////////////////////////////////
    // 3 components swizzles operators

    template <typename T>
    _xvec3<T> _xvec3<T>::_xxx() const
    {
        return _xvec3<T>(this->x, this->x, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yxx() const
    {
        return _xvec3<T>(this->y, this->x, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zxx() const
    {
        return _xvec3<T>(this->z, this->x, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xyx() const
    {
        return _xvec3<T>(this->x, this->y, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yyx() const
    {
        return _xvec3<T>(this->y, this->y, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zyx() const
    {
        return _xvec3<T>(this->z, this->y, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xzx() const
    {
        return _xvec3<T>(this->x, this->z, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yzx() const
    {
        return _xvec3<T>(this->y, this->z, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zzx() const
    {
        return _xvec3<T>(this->z, this->z, this->x);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xxy() const
    {
        return _xvec3<T>(this->x, this->x, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yxy() const
    {
        return _xvec3<T>(this->y, this->x, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zxy() const
    {
        return _xvec3<T>(this->z, this->x, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xyy() const
    {
        return _xvec3<T>(this->x, this->y, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yyy() const
    {
        return _xvec3<T>(this->y, this->y, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zyy() const
    {
        return _xvec3<T>(this->z, this->y, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xzy() const
    {
        return _xvec3<T>(this->x, this->z, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yzy() const
    {
        return _xvec3<T>(this->y, this->z, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zzy() const
    {
        return _xvec3<T>(this->z, this->z, this->y);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xxz() const
    {
        return _xvec3<T>(this->x, this->x, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yxz() const
    {
        return _xvec3<T>(this->y, this->x, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zxz() const
    {
        return _xvec3<T>(this->z, this->x, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xyz() const
    {
        return _xvec3<T>(this->x, this->y, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yyz() const
    {
        return _xvec3<T>(this->y, this->y, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zyz() const
    {
        return _xvec3<T>(this->z, this->y, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_xzz() const
    {
        return _xvec3<T>(this->x, this->z, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_yzz() const
    {
        return _xvec3<T>(this->y, this->z, this->z);
    }

    template <typename T>
    _xvec3<T> _xvec3<T>::_zzz() const
    {
        return _xvec3<T>(this->z, this->z, this->z);
    }

    // 4 components swizzles operators
    template <typename T>
    _xvec4<T> _xvec3<T>::_xxxx() const
    {
        return _xvec4<T>(this->x, this->x, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxxx() const
    {
        return _xvec4<T>(this->y, this->x, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxxx() const
    {
        return _xvec4<T>(this->z, this->x, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyxx() const
    {
        return _xvec4<T>(this->x, this->y, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyxx() const
    {
        return _xvec4<T>(this->y, this->y, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyxx() const
    {
        return _xvec4<T>(this->z, this->y, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzxx() const
    {
        return _xvec4<T>(this->x, this->z, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzxx() const
    {
        return _xvec4<T>(this->y, this->z, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzxx() const
    {
        return _xvec4<T>(this->z, this->z, this->x, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxyx() const
    {
        return _xvec4<T>(this->x, this->x, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxyx() const
    {
        return _xvec4<T>(this->y, this->x, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxyx() const
    {
        return _xvec4<T>(this->z, this->x, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyyx() const
    {
        return _xvec4<T>(this->x, this->y, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyyx() const
    {
        return _xvec4<T>(this->y, this->y, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyyx() const
    {
        return _xvec4<T>(this->z, this->y, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzyx() const
    {
        return _xvec4<T>(this->x, this->z, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzyx() const
    {
        return _xvec4<T>(this->y, this->z, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzyx() const
    {
        return _xvec4<T>(this->z, this->z, this->y, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxzx() const
    {
        return _xvec4<T>(this->x, this->x, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxzx() const
    {
        return _xvec4<T>(this->y, this->x, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxzx() const
    {
        return _xvec4<T>(this->z, this->x, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyzx() const
    {
        return _xvec4<T>(this->x, this->y, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyzx() const
    {
        return _xvec4<T>(this->y, this->y, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyzx() const
    {
        return _xvec4<T>(this->z, this->y, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzzx() const
    {
        return _xvec4<T>(this->x, this->z, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzzx() const
    {
        return _xvec4<T>(this->y, this->z, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzzx() const
    {
        return _xvec4<T>(this->z, this->z, this->z, this->x);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxxy() const
    {
        return _xvec4<T>(this->x, this->x, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxxy() const
    {
        return _xvec4<T>(this->y, this->x, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxxy() const
    {
        return _xvec4<T>(this->z, this->x, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyxy() const
    {
        return _xvec4<T>(this->x, this->y, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyxy() const
    {
        return _xvec4<T>(this->y, this->y, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyxy() const
    {
        return _xvec4<T>(this->z, this->y, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzxy() const
    {
        return _xvec4<T>(this->x, this->z, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzxy() const
    {
        return _xvec4<T>(this->y, this->z, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzxy() const
    {
        return _xvec4<T>(this->z, this->z, this->x, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxyy() const
    {
        return _xvec4<T>(this->x, this->x, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxyy() const
    {
        return _xvec4<T>(this->y, this->x, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxyy() const
    {
        return _xvec4<T>(this->z, this->x, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyyy() const
    {
        return _xvec4<T>(this->x, this->y, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyyy() const
    {
        return _xvec4<T>(this->y, this->y, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyyy() const
    {
        return _xvec4<T>(this->z, this->y, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzyy() const
    {
        return _xvec4<T>(this->x, this->z, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzyy() const
    {
        return _xvec4<T>(this->y, this->z, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzyy() const
    {
        return _xvec4<T>(this->z, this->z, this->y, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxzy() const
    {
        return _xvec4<T>(this->x, this->x, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxzy() const
    {
        return _xvec4<T>(this->y, this->x, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxzy() const
    {
        return _xvec4<T>(this->z, this->x, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyzy() const
    {
        return _xvec4<T>(this->x, this->y, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyzy() const
    {
        return _xvec4<T>(this->y, this->y, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyzy() const
    {
        return _xvec4<T>(this->z, this->y, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzzy() const
    {
        return _xvec4<T>(this->x, this->z, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzzy() const
    {
        return _xvec4<T>(this->y, this->z, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzzy() const
    {
        return _xvec4<T>(this->z, this->z, this->z, this->y);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxxz() const
    {
        return _xvec4<T>(this->x, this->x, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxxz() const
    {
        return _xvec4<T>(this->y, this->x, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxxz() const
    {
        return _xvec4<T>(this->z, this->x, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyxz() const
    {
        return _xvec4<T>(this->x, this->y, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyxz() const
    {
        return _xvec4<T>(this->y, this->y, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyxz() const
    {
        return _xvec4<T>(this->z, this->y, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzxz() const
    {
        return _xvec4<T>(this->x, this->z, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzxz() const
    {
        return _xvec4<T>(this->y, this->z, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzxz() const
    {
        return _xvec4<T>(this->z, this->z, this->x, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxyz() const
    {
        return _xvec4<T>(this->x, this->x, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxyz() const
    {
        return _xvec4<T>(this->y, this->x, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxyz() const
    {
        return _xvec4<T>(this->z, this->x, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyyz() const
    {
        return _xvec4<T>(this->x, this->y, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyyz() const
    {
        return _xvec4<T>(this->y, this->y, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyyz() const
    {
        return _xvec4<T>(this->z, this->y, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzyz() const
    {
        return _xvec4<T>(this->x, this->z, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzyz() const
    {
        return _xvec4<T>(this->y, this->z, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzyz() const
    {
        return _xvec4<T>(this->z, this->z, this->y, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xxzz() const
    {
        return _xvec4<T>(this->x, this->x, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yxzz() const
    {
        return _xvec4<T>(this->y, this->x, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zxzz() const
    {
        return _xvec4<T>(this->z, this->x, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xyzz() const
    {
        return _xvec4<T>(this->x, this->y, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yyzz() const
    {
        return _xvec4<T>(this->y, this->y, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zyzz() const
    {
        return _xvec4<T>(this->z, this->y, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_xzzz() const
    {
        return _xvec4<T>(this->x, this->z, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_yzzz() const
    {
        return _xvec4<T>(this->y, this->z, this->z, this->z);
    }

    template <typename T>
    _xvec4<T> _xvec3<T>::_zzzz() const
    {
        return _xvec4<T>(this->z, this->z, this->z, this->z);
    }
} //namespace glm

#endif//__xvec3_inl__
