//
//  Triangle.cpp
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#include "Triangle.h"
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
    a=new TRI_Edge();
    b=new TRI_Edge();
    c=new TRI_Edge();
}