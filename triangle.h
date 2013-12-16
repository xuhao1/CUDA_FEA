//
//  triangle.h
//  T13
//
//  Created by xuhao on 13-12-7.
//  Copyright (c) 2013年 xuhao. All rights reserved.
#ifndef __CUDA_FEA__TRIANGLE__
#define __CUDA_FEA__TRIANGLE__

#include"site.h"
class FEA_TRI_Site :public site//用于FEA计算的三角形网格点
{
public:
	double T;
	FEA_TRI_Site(site a):
		site(a.loc)
	{
	}

};
class TRI_Edge
{
public:
	FEA_TRI_Site*l,*r;
	double length();
};
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

bool Triangle::inTriangle(site p)
{
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;

	if (onEdge(p))
		return false;
	if( (pa%pb)*(pb%pc)/((pa+pb+pc).abs())>CLOSE_DIS2 )
		return true;
	else
		return false;
}
bool Triangle::onEdge(site p)
{
	if(onPoint(p))
		return 1;
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;
	double a=pa%pb,b=pb%pc,c=pc%pa;
	double d=pa.abs()*pb.abs()*pc.abs();
	if(fabs(a*b*c)/d<CLOSE_DIS2)
		return true;
	return false;
}
bool Triangle::onPoint(site p)
{
	vector2f pa=A->loc-p.loc;
	vector2f pb=B->loc-p.loc;
	vector2f pc=C->loc-p.loc;
	double a=pa.abs(),b=pb.abs(),c=pc.abs();
	if(fabs(a*b*c/(a+b+c))<CLOSE_DIS2)
		return true;
	return false;
}
Triangle::Triangle(site**p)
{
	A=new FEA_TRI_Site(*p[0]);
	B=new FEA_TRI_Site(*p[1]);
	C=new FEA_TRI_Site(*p[2]);
}
#endif