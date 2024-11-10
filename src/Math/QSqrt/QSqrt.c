/*
 * @Author: xixi_
 * @Date: 2024-10-06 13:13:21
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-10 15:35:45
 * @FilePath: /libminicalci/src/Math/Qsqrt/Qsqrt.c
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
#include "QSqrt.h"
float QSqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;           /* evil floating point bit level hacking */
    i = 0x5f3759df - (i >> 1); /* what the fuck? */
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y)); /* 1st iteration */
    y = y * (threehalfs - (x2 * y * y)); /* 2nd iteration, this can be removed */

    return y;
}