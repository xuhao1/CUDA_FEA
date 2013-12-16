//
//  pre_tri_cpu.cpp
//  CUDA_FEA
//
//  Created by xuhao on 13-12-16.
//  Copyright (c) 2013年 xuhao. All rights reserved.
//

#include "pre_tri_cpu.h"
using namespace std;

pre_tri_cpu::pre_tri_cpu(std::vector<vector2f >sites)
{
	double maxx,maxy,minx,miny;
	for(vector2f a:sites)
	{
		if(maxx<a.x)
			maxx=a.x;
		if(maxy<a.y)
			maxy=a.y;
		if(minx>a.x)
			minx=a.x;
		if(miny>a.y)
			miny=a.y;
	}
}

int tt_main()
{
	site **xin=new site*[3];
	xin[0]=new site(0,0);
	xin[1]=new site(0.01,0);
	xin[2]=new site(0,1);
	site yang(0.001,0.01);
	Triangle Qi(xin);
	cout<<"inTri:"<<Qi.inTriangle(yang)<<endl;
	cout<<"onEdge:"<<Qi.onEdge(yang)<<endl;
	cout<<"onPoint:"<<Qi.onPoint(yang)<<endl;
    return 0;
    
}
