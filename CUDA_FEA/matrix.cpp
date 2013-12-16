//
//  matrix.cpp
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#include "matrix.h"
matrix::matrix(int _row,int _col):
row(_row),col(_col)
{
	data=new double*[row+1];
    
	for(int i=1;i<=row;i++)
	{
		data[i]=new double[col+1];
		memset(data[i],0,(col+1)*sizeof(double));
	}
    
}

matrix::~matrix()
{
    /*
     for(int i=1;i<=row;i++)
     delete[](data[i]);
     
     delete[] (data);
     */
}

matrix& matrix::operator=(const matrix&a)
{
	row=a.row;
	col=a.col;
	data=new double*[col+1];
	for(int i=1;i<=row;i++)
    {
        data[i]=new double(col+1);
		memcpy(data[i],a[i],(col+1)*sizeof(double));
    }
	return *this;
}

std::ostream& operator<<(std::ostream& os,const matrix &objects)
{
	os<<"\n";
	for(int i=1;i<=objects.row;i++)
	{
		for(int j=1;j<=objects.col;j++)
		{
			os<<objects[i][j]<<" ";
		}
		os<<"\n";
	}
    return os;
}

double* & matrix::operator[](const int index)
{
	return data[index];
}

double* & matrix::operator[](const int index) const
{
	return data[index];
}

matrix operator+(matrix a,matrix b)
{
	if(a.row!=b.row||a.col!=b.col)
		return matrix(0,0);
	matrix c(a.row,a.col);
	for(int i=1;i<=a.row;i++)
		for(int j=1;j<=a.col;j++)
			c[i][j]=a[i][j]+b[i][j];
    
	return c;
}
matrix operator*(matrix a,matrix b)
{
	if(a.col!=b.row)
		return matrix(0,0);
	matrix c(a.row,b.col);
	for(int i=1;i<=a.row;i++)
		for(int j=1;j<=b.col;j++)
		{
			for(int k=1;k<=a.col;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
	return c;
}
double matrix::det()
{
    return 0;
	
}
matrix matrix::Inverse()
{
    return matrix(0,0);
}