#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fcn.hpp"



using namespace std;




double composite_int(Fcn & f, const double a,const double b,const int n){
	//get midpoint
	double h = (b-a)/n;

	//set weights
	double x1 = -0.86113631159405;
	double x2 = -0.33998104358486;
	double x3 = 0.33998104358486;
	double x4 = 0.86113631159405;
	double w1 = 0.34785484513745;
	double w2 = 0.65214515486254;
	double w3 = 0.65214515486255;
	double w4 = 0.34785484513745;

	double result=0.0;

	double xmid,node1, node2,node3,node4;

	for(int i=0 ;i<n;i++){

		xmid= a+ (i+0.5)*h;
		node1= xmid+ 0.5*h*x1;
		node2= xmid+ 0.5*h*x2;
		node3= xmid+ 0.5*h*x3;
		node4= xmid+ 0.5*h*x4;

		result+=w1*f(node1)+w2*f(node2)+w3*f(node3) + w4*f(node4);
	}

	return (0.5*h*result);
}
