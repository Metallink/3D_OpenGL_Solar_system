//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-21
// Updated : 2005-12-21
// Licence : This source is under GNU LGPL licence
// File    : gtx_round.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
// - GL_GTX_double
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_round_h__
#define __gtx_round_h__

#define GLM_GTX_round 1
#include "../glm.h"

namespace glm
{
    template <typename genType> genType roundGTX(const genType & x); //!< \brief Computes the component-wise round value of x (from GLM_GTX_round extension)
    float roundGTX(float x); //!< \brief Computes the round value of x (from GLM_GTX_round extension)
    double roundGTX(double x); //!< \brief Computes the round value of x (from GLM_GTX_round extension)
}

#endif//__gtx_round_h__
