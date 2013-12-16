//
//  FEA_TRI_Site.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__FEA_TRI_Site__
#define __CUDA_FEA__FEA_TRI_Site__
#include "site.h"
#include <iostream>
class FEA_TRI_Site :public site//用于FEA计算的三角形网格点
{
public:
	double T;
	FEA_TRI_Site(site a):
    site(a.loc)
	{
	}
    
};

#endif /* defined(__CUDA_FEA__FEA_TRI_Site__) */
