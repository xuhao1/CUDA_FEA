//
//  Triangle.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__Triangle__
#define __CUDA_FEA__Triangle__

#define CLOSE_DIS1 1e-5
#define CLOSE_DIS2 1e-10
#define CLOSE_DIS3 1e-15

#include <iostream>
#include "FEA_TRI_Site.h"
#include "TRI_Edge.h"
#include "vector2f.h"
class Triangle//用于FEA/FVM计算的通用三角形模块
{
public:
	Triangle();
	Triangle(site**);
	Triangle(site*);
	Triangle(FEA_TRI_Site**);
	~Triangle()
	{
		delete a;
		delete b;
		delete c;
        
		delete A;
		delete B;
		delete C;
	}
	TRI_Edge *a,*b,*c;//对边
	FEA_TRI_Site *A,*B,*C;
	Triangle* Divide_By_Point(FEA_TRI_Site p);
	bool inTriangle(site);
	bool onEdge(site);
	bool onPoint(site);
};
#endif /* defined(__CUDA_FEA__Triangle__) */
