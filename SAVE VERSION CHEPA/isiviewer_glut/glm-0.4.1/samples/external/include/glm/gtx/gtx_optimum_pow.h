//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-27
// Licence : This source is under GNU LGPL licence
// File    : gtx_optimum_pow.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_optimum_pow_h__
#define __gtx_optimum_pow_h__

#define GLM_GTX_optimum_pow 1
#include "../glm.h"

namespace glm
{
    template <typename genType> genType pow2GTX(const genType& x); //!< \brief Returns x raised to the power of 2. (From GLM_GTX_optimum_pow extension)
    template <typename genType> genType pow3GTX(const genType& x); //!< \brief Returns x raised to the power of 3. (From GLM_GTX_optimum_pow extension)
    template <typename genType> genType pow4GTX(const genType& x); //!< \brief Returns x raised to the power of 4. (From GLM_GTX_optimum_pow extension)
    
    bool powOfTwoGTX(int num); //!< \brief Checks if the parameter is a power of 2 number. (From GLM_GTX_optimum_pow extension)
    _bvec2 powOfTwoGTX(const _xvec2<int>& x); //!< \brief Checks to determine if the parameter component are power of 2 numbers. (From GLM_GTX_optimum_pow extension)
    _bvec3 powOfTwoGTX(const _xvec3<int>& x); //!< \brief Checks to determine if the parameter component are power of 2 numbers. (From GLM_GTX_optimum_pow extension)
    _bvec4 powOfTwoGTX(const _xvec4<int>& x); //!< \brief Checks to determine if the parameter component are power of 2 numbers. (From GLM_GTX_optimum_pow extension)
}

#endif//__gtx_optimum_pow_h__
