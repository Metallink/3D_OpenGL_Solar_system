//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-07
// Updated : 2006-01-07
// Licence : This source is under GNU LGPL licence
// File    : gtx_extend.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_extend_h__
#define __gtx_extend_h__

#define GLM_GTX_extend 1
#include "../glm.h"

namespace glm
{
	template <typename T> T extend(const T Origin, const T Source, const T Length); //!< \brief Extends of Length the Origin position using the (Source - Origin) direction (from GLM_GTX_extend extension)
	template <typename T> _xvec2<T> extend(const _xvec2<T>& Origin, const _xvec2<T>& Source, const T Length); //!< \brief Extends of Length the Origin position using the (Source - Origin) direction (from GLM_GTX_extend extension)
	template <typename T> _xvec3<T> extend(const _xvec3<T>& Origin, const _xvec3<T>& Source, const T Length); //!< \brief Extends of Length the Origin position using the (Source - Origin) direction (from GLM_GTX_extend extension)
	template <typename T> _xvec4<T> extend(const _xvec4<T>& Origin, const _xvec4<T>& Source, const T Length); //!< \brief Extends of Length the Origin position using the (Source - Origin) direction (from GLM_GTX_extend extension)
}

#endif//__gtx_extend_h__
