#include"pre_tri_cpu.h"
#include<iostream>
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
int main()
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


}
