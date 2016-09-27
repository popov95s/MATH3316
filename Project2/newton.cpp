#include <iostream>
#include "matrix.cpp"
#include "fcn.hpp"
#include "bisection.cpp"
#include <math.h>

double newton(Fcn& f, Fcn& df, double x, int maxit, double tol, bool show_iterates);


class f: public Fcn{
public:
  double operator()(double x) {   // function evaluation
    return x*x*(x-3)*(x+2);
  }
};

class derf: public Fcn{
public:
  double operator()(double x) {   // function evaluation
    return x*(4*x*x - 3*x - 12);
  }
};

int main(){
	f func;
	derf derfunc;
	double tol[3]= { pow(10.0,-1.0),pow(10.0,-5.0),pow(10.0,-9.0)};
	double x0[3]= {-3,1,2};
	for (int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			cout<<newton(func,derfunc,x0[i],50,tol[j],true)<<endl<<endl;
		}
	}
}

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