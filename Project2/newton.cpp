#include <math.h>
#include <iostream>
#include "fcn.hpp"
#include <stdlib.h>

using namespace std;

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates){
	double x1=0.0;
	for ( int i=1; i< maxit; i++){
		double y0 = f(x);
		double yp = df(x);
		x1= x-y0/yp;

		if(show_iterates){
			cout<<i<<"\t"<<x1<<"\t"<<f(x1)<<endl;
		}
		if(abs(f(x1))<tol)
			break;
		else{
			x=x1;
		}
	}
	return x1;
}