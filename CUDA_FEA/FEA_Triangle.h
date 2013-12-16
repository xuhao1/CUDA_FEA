//
//  FEA_Triangle.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__FEA_Triangle__
#define __CUDA_FEA__FEA_Triangle__

#include <iostream>
#include"triangle.h"
#include"matrix.h"
class FEA_Triangle:Triangle
{
public:
    matrix COOR;
	FEA_Triangle():
        Triangle(),COOR(3,2)
	{
	};
	~FEA_Triangle()
	{
	};
	
};
#endif /* defined(__CUDA_FEA__FEA_Triangle__) */
