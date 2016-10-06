/*
MATH3316 Project2 
Author: Stefan Popov
Oct 5th 2016
*/

#include <math.h>
#include <iostream>
#include "fcn.hpp"
//#include <stdlib.h>

using namespace std;


//Newton function written from pseudocode provided
double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates){
	//declare x1 =0
	double x1=0.0;
	if(show_iterates){
		cout<<"Iteration \t x \t f(x1)"<<endl;
	}
	//loop as much as maxit allows and evaluate using newton. Break if tolerance is exceeded.
	for ( int i=1; i< maxit; i++){
		double y0 = f(x);
		double yp = df(x);
		x1= x-y0/yp;

		if(show_iterates){
			cout<<i<<"\t"<<x1<<"\t"<<f(x1)<<endl;
		}
		if(fabs(f(x1))<tol)
			break;
		else{
			x=x1;
		}
	}
	//return result
	return x1;
}