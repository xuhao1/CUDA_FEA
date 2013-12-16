//
//  TRI_Edge.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__TRI_Edge__
#define __CUDA_FEA__TRI_Edge__
#include "FEA_TRI_Site.h"
#include <iostream>
class TRI_Edge
{
public:
	FEA_TRI_Site*l,*r;
	double length();
};
#endif /* defined(__CUDA_FEA__TRI_Edge__) */
