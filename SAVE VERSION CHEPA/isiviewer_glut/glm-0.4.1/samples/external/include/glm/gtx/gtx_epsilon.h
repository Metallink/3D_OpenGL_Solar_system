//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2006-01-16
// Licence : This source is under GNU LGPL licence
// File    : gtx_epsilon.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GLM_GTX_double
// - GLM_GTX_half
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_epsilon_h__
#define __gtx_epsilon_h__

#define GLM_GTX_epsilon 1
#include "../glm.h"

namespace glm
{
    template <typename T> T equalEpsilonGTX(T x, T y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> T notEqualEpsilonGTX(T x, T y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)

    template <typename T> _bvec2 equalEpsilonGTX(const _xvec2<T>& x, const _xvec2<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec3 equalEpsilonGTX(const _xvec3<T>& x, const _xvec3<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec4 equalEpsilonGTX(const _xvec4<T>& x, const _xvec4<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec2 notEqualEpsilonGTX(const _xvec2<T>& x, const _xvec2<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec3 notEqualEpsilonGTX(const _xvec3<T>& x, const _xvec3<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec4 notEqualEpsilonGTX(const _xvec4<T>& x, const _xvec4<T>& y, T epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)

    template <typename T> _bvec2 equalEpsilonGTX(const _xvec2<T>& x, const _xvec2<T>& y, const _xvec2<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec3 equalEpsilonGTX(const _xvec3<T>& x, const _xvec3<T>& y, const _xvec3<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec4 equalEpsilonGTX(const _xvec4<T>& x, const _xvec4<T>& y, const _xvec4<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| < epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec2 notEqualEpsilonGTX(const _xvec2<T>& x, const _xvec2<T>& y, const _xvec2<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec3 notEqualEpsilonGTX(const _xvec3<T>& x, const _xvec3<T>& y, const _xvec3<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)
    template <typename T> _bvec4 notEqualEpsilonGTX(const _xvec4<T>& x, const _xvec4<T>& y, const _xvec4<T>& epsilon); //!< \brief Returns the component-wise compare of |x - y| >= epsilon (from GLM_GTX_epsilon extension)
}

#endif//__gtx_epsilon_h__
