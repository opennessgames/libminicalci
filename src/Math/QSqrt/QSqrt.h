/*
 * @Author: xixi_
 * @Date: 2024-10-06 13:18:59
 * @LastEditors: xixi_
 * @LastEditTime: 2024-11-10 15:36:02
 * @FilePath: /libminicalci/src/Math/Qsqrt/QSqrt.h
 * Copyright (c) 2023-2024 by xixi_ , All Rights Reserved.
 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef Q_SQRT_H
#define Q_SQRT_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
extern "C"
{
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @brief 计算给定数值的平方根倒数
     * @anchor John Carmack
     *
     * @param number 输入的浮点数
     * @return 返回输入数值的平方根倒数
     *
     * @note 使用此函数可获得快速的平方根倒数估算
     */
    float QSqrt(float);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // Q_SQRT_H