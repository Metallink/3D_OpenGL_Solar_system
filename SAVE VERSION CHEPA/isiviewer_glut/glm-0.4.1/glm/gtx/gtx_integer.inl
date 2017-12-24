//////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 G-Truc Creation (www.g-truc.net)
//////////////////////////////////////////////////////////////////////////////////
// Author  : Christophe [Groove] Riccio (contact [at] g-truc [point] net)
// Created : 2005-12-24
// Updated : 2006-01-30
// Licence : This source is under GNU LGPL licence
// File    : gtx_integer.inl
//////////////////////////////////////////////////////////////////////////////////

#ifndef __gtx_integer_inl__
#define __gtx_integer_inl__

#include "gtx_integer.h"

namespace glm
{
    // powGTX
    inline int powGTX(int x, int y)
    {
        int result = x;
        for(int i = 1; i < y; ++i)
            result *= x;
        return result;
    }

    inline _xvec2<int> powGTX(const _xvec2<int>& x, const _xvec2<int>& y)
    {
        return _xvec2<int>(
            powGTX(x.x, y.x),
            powGTX(x.y, y.y));
    }

    inline _xvec3<int> powGTX(const _xvec3<int>& x, const _xvec3<int>& y)
    {
        return _xvec3<int>(
            powGTX(x.x, y.x),
            powGTX(x.y, y.y),
            powGTX(x.z, y.z));
    }

    inline _xvec4<int> powGTX(const _xvec4<int>& x, const _xvec4<int>& y)
    {
        return _xvec4<int>(
            powGTX(x.x, y.x),
            powGTX(x.y, y.y),
            powGTX(x.z, y.z),
            powGTX(x.w, y.w));
    }

    // sqrtGTX: From Christopher J. Musial, An integer square root, Graphics Gems, 1990, page 387
    inline int sqrtGTX(int x)
    {
        if(x <= 1) return x;

        int NextTrial = x >> 1;
        int CurrentAnswer;

        do
        {
            CurrentAnswer = NextTrial;
            NextTrial = (NextTrial + x / NextTrial) >> 1;
        } while(NextTrial < CurrentAnswer);

        return CurrentAnswer;
    }

    inline _xvec2<int> sqrtGTX(const _xvec2<int>& x)
    {
        return _xvec2<int>(
            sqrtGTX(x.x),
            sqrtGTX(x.y));
    }

    inline _xvec3<int> sqrtGTX(const _xvec3<int>& x)
    {
        return _xvec3<int>(
            sqrtGTX(x.x),
            sqrtGTX(x.y),
            sqrtGTX(x.z));
    }

    inline _xvec4<int> sqrtGTX(const _xvec4<int>& x)
    {
        return _xvec4<int>(
            sqrtGTX(x.x),
            sqrtGTX(x.y),
            sqrtGTX(x.z),
            sqrtGTX(x.w));
    }

    // absGTX
    inline int absGTX(int x)
    {
        return ((x >> 31) ^ x) - (x >> 31);
    }

    inline _xvec2<int> absGTX(const _xvec2<int>& x)
    {
        return _xvec2<int>(
            absGTX(x.x),
            absGTX(x.y));
    }

    inline _xvec3<int> absGTX(const _xvec3<int>& x)
    {
        return _xvec3<int>(
            absGTX(x.x),
            absGTX(x.y),
            absGTX(x.z));
    }

    inline _xvec4<int> absGTX(const _xvec4<int>& x)
    {
        return _xvec4<int>(
            absGTX(x.x),
            absGTX(x.y),
            absGTX(x.z),
            absGTX(x.w));
    }

    // signGTX
    inline int signGTX(int x)
    {
        int result;
        if(x > 0)
            result = 1;
        else if(x < 0)
            result = -1;
        else
            result = 0;
        return result;
    }

    inline _xvec2<int> signGTX(const _xvec2<int>& x)
    {
        return _xvec2<int>(
            signGTX(x.x),
            signGTX(x.y));
    }

    inline _xvec3<int> signGTX(const _xvec3<int>& x)
    {
        return _xvec3<int>(
            signGTX(x.x),
            signGTX(x.y),
            signGTX(x.z));
    }

    inline _xvec4<int> signGTX(const _xvec4<int>& x)
    {
        return _xvec4<int>(
            signGTX(x.x),
            signGTX(x.y),
            signGTX(x.z),
            signGTX(x.w));
    }

    // modGTX
    inline int modGTX(int x, int y)
    {
        return x - y * (x / y);
    }

    inline _xvec2<int> modGTX(const _xvec2<int>& x, int y)
    {
        return _xvec2<int>(
            modGTX(x.x, y),
            modGTX(x.y, y));
    }

    inline _xvec3<int> modGTX(const _xvec3<int>& x, int y)
    {
        return _xvec3<int>(
            modGTX(x.x, y),
            modGTX(x.y, y),
            modGTX(x.z, y));
    }

    inline _xvec4<int> modGTX(const _xvec4<int>& x, int y)
    {
        return _xvec4<int>(
            modGTX(x.x, y),
            modGTX(x.y, y),
            modGTX(x.z, y),
            modGTX(x.w, y));
    }

    inline _xvec2<int> modGTX(const _xvec2<int>& x, const _xvec2<int>& y)
    {
        return _xvec2<int>(
            modGTX(x.x, y.x),
            modGTX(x.y, y.y));
    }

    inline _xvec3<int> modGTX(const _xvec3<int>& x, const _xvec3<int>& y)
    {
        return _xvec3<int>(
            modGTX(x.x, y.x),
            modGTX(x.y, y.y),
            modGTX(x.z, y.z));
    }

    inline _xvec4<int> modGTX(const _xvec4<int>& x, const _xvec4<int>& y)
    {
        return _xvec4<int>(
            modGTX(x.x, y.x),
            modGTX(x.y, y.y),
            modGTX(x.z, y.z),
            modGTX(x.w, y.w));
    }

    // minGTX
    // test: 
    /*
    inline int minGTX(int x, int y)
    {
        return (x + y - glm::absGTX(x - y)) >> 1;
    }
    */
    inline int minGTX(int x, int y)
    {
        return x < y ? x : y;
    }

    inline _xvec2<int> minGTX(const _xvec2<int>& x, int y)
    {
        return _xvec2<int>(
            minGTX(x.x, y),
            minGTX(x.y, y));
    }

    inline _xvec3<int> minGTX(const _xvec3<int>& x, int y)
    {
        return _xvec3<int>(
            minGTX(x.x, y),
            minGTX(x.y, y),
            minGTX(x.z, y));
    }

    inline _xvec4<int> minGTX(const _xvec4<int>& x, int y)
    {
        return _xvec4<int>(
            minGTX(x.x, y),
            minGTX(x.y, y),
            minGTX(x.z, y),
            minGTX(x.w, y));
    }

    inline _xvec2<int> minGTX(const _xvec2<int>& x, const _xvec2<int>& y)
    {
        return _xvec2<int>(
            minGTX(x.x, y.x),
            minGTX(x.y, y.y));
    }

    inline _xvec3<int> minGTX(const _xvec3<int>& x, const _xvec3<int>& y)
    {
        return _xvec3<int>(
            minGTX(x.x, y.x),
            minGTX(x.y, y.y),
            minGTX(x.z, y.z));
    }

    inline _xvec4<int> minGTX(const _xvec4<int>& x, const _xvec4<int>& y)
    {
        return _xvec4<int>(
            minGTX(x.x, y.x),
            minGTX(x.y, y.y),
            minGTX(x.z, y.z),
            minGTX(x.w, y.w));
    }

    // maxGTX
    inline int maxGTX(int x, int y)
    {
        return x > y ? x : y;
    }

    inline _xvec2<int> maxGTX(const _xvec2<int>& x, int y)
    {
        return _xvec2<int>(
            maxGTX(x.x, y),
            maxGTX(x.y, y));
    }

    inline _xvec3<int> maxGTX(const _xvec3<int>& x, int y)
    {
        return _xvec3<int>(
            maxGTX(x.x, y),
            maxGTX(x.y, y),
            maxGTX(x.z, y));
    }

    inline _xvec4<int> maxGTX(const _xvec4<int>& x, int y)
    {
        return _xvec4<int>(
            maxGTX(x.x, y),
            maxGTX(x.y, y),
            maxGTX(x.z, y),
            maxGTX(x.w, y));
    }

    inline _xvec2<int> maxGTX(const _xvec2<int>& x, const _xvec2<int>& y)
    {
        return _xvec2<int>(
            maxGTX(x.x, y.x),
            maxGTX(x.y, y.y));
    }

    inline _xvec3<int> maxGTX(const _xvec3<int>& x, const _xvec3<int>& y)
    {
        return _xvec3<int>(
            maxGTX(x.x, y.x),
            maxGTX(x.y, y.y),
            maxGTX(x.z, y.z));
    }

    inline _xvec4<int> maxGTX(const _xvec4<int>& x, const _xvec4<int>& y)
    {
        return _xvec4<int>(
            maxGTX(x.x, y.x),
            maxGTX(x.y, y.y),
            maxGTX(x.z, y.z),
            maxGTX(x.w, y.w));
    }

    // clampGTX
    inline int clampGTX(int x, int minVal, int maxVal)
    {
	    if(x >= maxVal) return maxVal;
        if(x <= minVal) return minVal;
	    return x;
    }

    inline _xvec2<int> clampGTX(const _xvec2<int>& x, int minVal, int maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    inline _xvec3<int> clampGTX(const _xvec3<int>& x, int minVal, int maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    inline _xvec4<int> clampGTX(const _xvec4<int>& x, int minVal, int maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    inline _xvec2<int> clampGTX(const _xvec2<int>& x, const _xvec2<int>& minVal, const _xvec2<int>& maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    inline _xvec3<int> clampGTX(const _xvec3<int>& x, const _xvec3<int>& minVal, const _xvec3<int>& maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    inline _xvec4<int> clampGTX(const _xvec4<int>& x, const _xvec4<int>& minVal, const _xvec4<int>& maxVal)
    {
        return glm::minGTX(glm::maxGTX(x, minVal), maxVal);
    }

    // factorial (!12 max)
    inline int factorialGTX(int x)
    {
        int Result;
        for(Result = 1; x > 1; --x)
            Result *= x;
        return Result;
    }

    inline _xvec2<int> factorialGTX(const _xvec2<int>& x)
    {
        return _xvec2<int>(
            factorialGTX(x.x),
            factorialGTX(x.y));
    }

    inline _xvec3<int> factorialGTX(const _xvec3<int>& x)
    {
        return _xvec3<int>(
            factorialGTX(x.x),
            factorialGTX(x.y),
            factorialGTX(x.z));
    }

    inline _xvec4<int> factorialGTX(const _xvec4<int>& x)
    {
        return _xvec4<int>(
            factorialGTX(x.x),
            factorialGTX(x.y),
            factorialGTX(x.z),
            factorialGTX(x.w));
    }
}

#endif//__gtx_integer_inl__
