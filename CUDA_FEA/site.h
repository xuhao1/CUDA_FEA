//
//  site.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.

//这个是计算网格点
//无论FEA,FVM,FDM，网格点都非常必要
//这里的格点作为基类给出，仅包含必要信息。

#ifndef __CUDA_FEA__site__
#define __CUDA_FEA__site__

#include <iostream>
#include "vector2f.h"

class site
{
public:
	vector2f loc;
	site()
	{
		loc.x=0;
		loc.y=0;
	}
	site(double x,double y)
	{
		loc.x=x;
		loc.y=y;
	}
	site(vector2f a)
	{
		loc=a;
	}
	
};


#endif /* defined(__CUDA_FEA__site__) */
