//
//  matrix.h
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#ifndef __CUDA_FEA__matrix__
#define __CUDA_FEA__matrix__

#include <iostream>


class matrix
{
public:
	int row;//行
	int col;//列
	double* &operator[](const int);
	double*&operator[](const int) const;
	matrix&operator=(const matrix&);
	matrix(int,int);
	~matrix();
	double det();
	matrix Inverse();
private:
	double **data;
};

std::ostream& operator<<(std::ostream& os,const matrix &objects);
matrix operator+(matrix a,matrix b);
matrix operator*(matrix a,matrix b);
#endif /* defined(__CUDA_FEA__matrix__) */
