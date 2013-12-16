//
//  vector2f.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__vector2f__
#define __CUDA_FEA__vector2f__

#include <iostream>
#include<math.h>
//对于二维坐标的基本定义与重载
//后期加入GPU计算部分
struct vector2f
{
	double x,y;
	vector2f()
	{
		x=0;
		y=0;
	}
	vector2f(double _x,double _y):
    x(_x),y(_y)
	{
	}
	double abs()
	{
		return sqrt(x*x+y*y);
	}
};
vector2f operator +(vector2f a,vector2f b);
vector2f operator -(vector2f a,vector2f b);
double operator *(vector2f a,vector2f b);//dot
vector2f operator *(vector2f a,double b);
vector2f operator/(vector2f a,double b);
double operator %(vector2f a,vector2f b);
#endif /* defined(__CUDA_FEA__vector2f__) */
