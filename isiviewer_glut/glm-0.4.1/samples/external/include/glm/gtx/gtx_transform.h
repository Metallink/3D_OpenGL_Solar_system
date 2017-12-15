//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_transform.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_transform_h__
#define __gtx_transform_h__

#define GLM_GTX_transform 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat4<T> translateGTX(T x, T y, T z); //!< /brief Builds a translation 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> translateGTX(const _xvec3<T> & v); //!< /brief Builds a translation 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> translateGTX(const _xmat4<T> & m, T x, T y, T z); //!< /brief Transforms a matrix with a translation 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> translateGTX(const _xmat4<T> & m, const _xvec3<T> & v); //!< /brief Transforms a matrix with a translation 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotateGTX(T angle, T x, T y, T z); //!< /brief Builds a rotation 4 * 4 matrix created from an axis of 3 scalars and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotateGTX(T angle, const _xvec3<T> & v); //!< /brief Builds a rotation 4 * 4 matrix created from an axis vector and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotateGTX(const _xmat4<T> & m, T angle, T x, T y, T z); //!< /brief Transforms a matrix with a rotation 4 * 4 matrix created from an axis of 3 scalars and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotateGTX(const _xmat4<T> & m, T angle, const _xvec3<T> & v); //!< /brief Transforms a matrix with a rotation 4 * 4 matrix created from an axis vector and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scaleGTX(T x, T y, T z); //!< /brief Builds a scale 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scaleGTX(const _xvec3<T> & v); //!< /brief Builds a scale 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scaleGTX(const _xmat4<T> & m, T x, T y, T z); //!< /brief Transforms a matrix with a scale 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scaleGTX(const _xmat4<T> & m, const _xvec3<T> & v); //!< /brief Transforms a matrix with a scale 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)

    // 3D
    template <typename T> _xmat4<T> translate3DGTX(const _xmat4<T> & m, T x, T y, T z); //!< /brief Transforms a matrix with a translation 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> translate3DGTX(const _xmat4<T> & m, const _xvec3<T> & v); //!< /brief Transforms a matrix with a translation 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotate3DGTX(const _xmat4<T> & m, T angle, T x, T y, T z); //!< /brief Transforms a matrix with a rotation 4 * 4 matrix created from an axis of 3 scalars and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> rotate3DGTX(const _xmat4<T> & m, T angle, const _xvec3<T> & v); //!< /brief Transforms a matrix with a rotation 4 * 4 matrix created from an axis vector and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> rotate3DGTX(const _xmat3<T> & m, T angle, T x, T y, T z); //!< /brief Transforms a matrix with a rotation 3 * 3 matrix created from an axis of 3 scalars and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> rotate3DGTX(const _xmat3<T> & m, T angle, const _xvec3<T> & v); //!< /brief Transforms a matrix with a rotation 3 * 3 matrix created from an axis vector and an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scale3DGTX(const _xmat4<T> & m, T x, T y, T z); //!< /brief Transforms a matrix with a scale 4 * 4 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat4<T> scale3DGTX(const _xmat4<T> & m, const _xvec3<T> & v); //!< /brief Transforms a matrix with a scale 4 * 4 matrix created from a vector of 3 components (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> scale3DGTX(const _xmat3<T> & m, T x, T y, T z); //!< /brief Transforms a matrix with a scale 3 * 3 matrix created from 3 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> scale3DGTX(const _xmat3<T> & m, const _xvec3<T> & v); //!< /brief Transforms a matrix with a scale 3 * 3 matrix created from a vector of 3 components (from GLM_GTX_transform extension)

    // 2D
    template <typename T> _xmat3<T> translate2DGTX(const _xmat3<T> & m, T x, T y); //!< /brief Translates a 3 * 3 matrix from 2 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> translate2DGTX(const _xmat3<T> & m, const _xvec2<T> & v); //!< /brief Translates a 3 * 3 matrix from a vector of 2 components (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> rotate2DGTX(const _xmat3<T> & m, T angle); //!< /brief Rotates a 3 * 3 matrix from an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat2<T> rotate2DGTX(const _xmat2<T> & m, T angle); //!< /brief Rotates a 2 * 2 matrix from an angle expressed in degrees (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> scale2DGTX(const _xmat3<T> & m, T x, T y); //!< /brief Scales a 3 * 3 matrix using 2 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat3<T> scale2DGTX(const _xmat3<T> & m, const _xvec2<T> & v); //!< /brief Scales a 3 * 3 matrix using a vector of 2 components (from GLM_GTX_transform extension)
    template <typename T> _xmat2<T> scale2DGTX(const _xmat2<T> & m, T x, T y); //!< /brief Scales a 2 * 2 matrix using 2 scalars (from GLM_GTX_transform extension)
    template <typename T> _xmat2<T> scale2DGTX(const _xmat2<T> & m, const _xvec2<T> & v); //!< /brief Scales a 2 * 2 matrix using a vector of 2 components (from GLM_GTX_transform extension)
}

#endif//__gtx_transform_h__
