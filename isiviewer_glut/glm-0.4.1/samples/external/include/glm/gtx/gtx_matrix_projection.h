//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_matrix_projection.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_matrix_projection_h__
#define __gtx_matrix_projection_h__

#define GLM_GTX_matrix_projection 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xmat4<T> ortho2DGTX(T left, T right, T bottom, T top); //!< \brief Creates a matrix for projecting two-dimensional coordinates onto the screen (from GLM_GTX_matrix_projection extension)
    template <typename T> _xmat4<T> ortho3DGTX(T left, T right, T bottom, T top, T zNear, T zFar); //!< \brief Creates a matrix for an orthographic parallel viewing volume (from GLM_GTX_matrix_projection extension)
    template <typename T> _xmat4<T> perspectiveGTX(T fovy, T aspect, T zNear, T zFar); //!< \brief Creates a matrix for a symmetric perspective-view frustum (from GLM_GTX_matrix_projection extension)
    template <typename T> _xmat4<T> infinitePerspectiveGTX(T fovy, T aspect, T zNear);  //!< \brief Creates a matrix for a symmetric perspective-view frustum with far plane at infinite (from GLM_GTX_matrix_projection extension)
    template <typename T> _xmat4<T> tweakedInfinitePerspectiveGTX(T fovy, T aspect, T zNear); //!< \brief Creates a matrix for a symmetric perspective-view frustum with far plane at infinite for graphics hardware that doesn't support depth clamping (from GLM_GTX_matrix_projection extension)
    template <typename T, typename U> _xvec3<T> projectGTX(const _xvec3<T>& obj, const _xmat4<T>& model, const _xmat4<T>& proj, const _xvec4<U>& view); //!< \brief Map the specified object coordinates (obj.x, obj.y, obj.z) into window coordinates (from GLM_GTX_matrix_projection extension)
    template <typename T, typename U> _xvec3<T> unProjectGTX(const _xvec3<T>& win, const _xmat4<T>& model, const _xmat4<T>& proj, const _xvec4<U>& view); //!< \brief Map the specified window coordinates (win.x, win.y, win.z) into object coordinates (from GLM_GTX_matrix_projection extension)
}

#endif//__gtx_matrix_projection_h__
