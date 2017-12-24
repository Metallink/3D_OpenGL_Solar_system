//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2006-01-16
// Updated : 2006-01-16
// Licence : This source is under GNU LGPL licence
// File    : gtx_random.h
//////////////////////////////////////////////////////////////////////////////////
// Dependency:
// - GLM version 1.0
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_random_h__
#define __gtx_random_h__

#define GLM_GTX_random 1
#include "../glm.h"

namespace glm
{
    float rand1GTX(); //!< \brief Returns a random value will range from [0.0, 1.0](from GLM_GTX_random extension)
    float rand1GTX(float min, float max); //!< \brief Returns a random value will range from [min, max](from GLM_GTX_random extension)
    
    _xvec2<float> rand2GTX(); //!< \brief Returns a random normalized vector of 2 components (from GLM_GTX_random extension)
    _xvec2<float> rand2GTX(float min, float max); //!< \brief Returns a random vector of 2 components witch length will range from [min, max] (from GLM_GTX_random extension)
    
    _xvec3<float> rand3GTX(); //!< \brief Returns a random normalized vector of 3 components (from GLM_GTX_random extension)
    _xvec3<float> rand3GTX(float min, float max); //!< \brief Returns a random vector of 3 components witch length will range from [min, max] (from GLM_GTX_random extension)

    _xvec4<float> rand4GTX(); //!< \brief Returns a random normalized vector of 4 components (from GLM_GTX_random extension)
    _xvec4<float> rand4GTX(float min, float max); //!< \brief Returns a random vector of 4 components witch length will range from [min, max] (from GLM_GTX_random extension)

    template <typename T> T gauss1GTX(T mean, T std_deviation);
    template <typename T> _xvec2<T> gauss2GTX(T mean, T std_deviation);
    template <typename T> _xvec3<T> gauss3GTX(T mean, T std_deviation);
    template <typename T> _xvec4<T> gauss4GTX(T mean, T std_deviation);
}

#endif//__gtx_random_h__
