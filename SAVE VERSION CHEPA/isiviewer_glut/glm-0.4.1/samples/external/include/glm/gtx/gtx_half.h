//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2006-01-05
// Licence : This source is under GNU LGPL licence
// File    : gtx_half.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GL_GTX_quaternion
//////////////////////////////////////////////////////////////////////////////////
// ToDo:
// - Defined all the extensions
//////////////////////////////////////////////////////////////////////////////////
// Copyright:
// This half implementation is based on OpenEXR witch is Copyright (c) 2002, 
// Industrial Light & Magic, a division of Lucas Digital Ltd. LLC
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_half_h__
#define __gtx_half_h__

#define GLM_GTX_half 1
#include "../glm.h"
#include "gtx_quaternion.h"

namespace glm
{
	//! \brief Class for half-precision floating-point numbers. (From GLM_GTX_half extension)
    class __halfGTX
    {
    public:
	    // Constructors
        __halfGTX();
        __halfGTX(float s);
        __halfGTX(double s);
        __halfGTX(int s);

        operator float() const;
        operator double() const;
        operator int() const;

        // Operators
        __halfGTX& operator=(__halfGTX s);
        __halfGTX& operator=(float s);
	    __halfGTX operator+ (__halfGTX s) const;
	    __halfGTX& operator+= (__halfGTX s);
        __halfGTX operator+ (float s) const;
	    __halfGTX& operator+= (float s);
	    __halfGTX operator- (__halfGTX s) const;
	    __halfGTX& operator-= (__halfGTX s);
	    __halfGTX operator- (float s) const;
	    __halfGTX& operator-= (float s);
        __halfGTX operator* (__halfGTX s) const;
	    __halfGTX& operator*= (__halfGTX s);
        __halfGTX operator* (float s) const;
	    __halfGTX& operator*= (float s);
	    __halfGTX operator/ (__halfGTX s) const;
	    __halfGTX& operator/= (__halfGTX s);
	    __halfGTX operator/ (float s) const;
	    __halfGTX& operator/= (float s);
        __halfGTX operator- () const;
        __halfGTX operator++ ();
	    __halfGTX operator++ (int n) const;
	    __halfGTX operator-- ();
	    __halfGTX operator-- (int n) const;

    private:
        short data;

        short _toHalf(int i) const;
        int _toFloat(short h) const;
        float _overflow() const;

    private:
        union uif
        {
    	    int i;
	        float f;
        };
    };

    typedef _xvec2<__halfGTX> __hvec2GTX; //!< \brief Vector of 2 half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xvec3<__halfGTX> __hvec3GTX; //!< \brief Vector of 3 half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xvec4<__halfGTX> __hvec4GTX; //!< \brief Vector of 4 half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xmat2<__halfGTX> __hmat2GTX; //!< \brief 2 * 2 matrix of half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xmat3<__halfGTX> __hmat3GTX; //!< \brief 3 * 3 matrix of half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xmat4<__halfGTX> __hmat4GTX; //!< \brief 4 * 4 matrix of half-precision floating-point numbers. (From GLM_GTX_half extension)
    typedef _xquat<__halfGTX> __hquatGTX; //!< \brief Quaternion of half-precision floating-point numbers. (from GLM_GTX_half extension)
}

#endif//__gtx_half_h__
