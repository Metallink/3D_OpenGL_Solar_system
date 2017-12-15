//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_matrix_selection.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_matrix_selection_h__
#define __gtx_matrix_selection_h__

#define GLM_GTX_matrix_selection 1
#include "../glm.h"

namespace glm
{
    template <typename T> _xvec2<T> rowGTX(const _xmat2<T>& m, int index); //!< \brief Returns a 2 components vector that contains the row of the matrix m witch values is the ones of the row index (from GLM_GTX_matrix_selection extension)
    template <typename T> _xvec3<T> rowGTX(const _xmat3<T>& m, int index); //!< \brief Returns a 3 components vector that contains the row of the matrix m witch values is the ones of the row index (from GLM_GTX_matrix_selection extension)
    template <typename T> _xvec4<T> rowGTX(const _xmat4<T>& m, int index); //!< \brief Returns a 4 components vector that contains the row of the matrix m witch values is the ones of the row index (from GLM_GTX_matrix_selection extension)
    template <typename T> _xvec2<T> columnGTX(const _xmat2<T>& m, int index); //!< \brief Returns a 2 components vector that contains the row of the matrix m witch values is the ones of the column index (from GLM_GTX_matrix_selection extension)
    template <typename T> _xvec3<T> columnGTX(const _xmat3<T>& m, int index); //!< \brief Returns a 3 components vector that contains the row of the matrix m witch values is the ones of the column index (from GLM_GTX_matrix_selection extension)
    template <typename T> _xvec4<T> columnGTX(const _xmat4<T>& m, int index); //!< \brief Returns a 4 components vector that contains the row of the matrix m witch values is the ones of the column index (from GLM_GTX_matrix_selection extension)
}

#endif//__gtx_matrix_selection_h__
