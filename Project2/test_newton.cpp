/*
MATH3316 Project2 
Author: Stefan Popov
Oct 5th 2016
*/
//#include "bisection.cpp"
#include "newton.cpp"

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
			cout<<"Calling newton for x0= "<<x0[i]<<" with tolerance tol= "<<tol[j]<<endl;
			cout<<"The result yielded was : "<<newton(func,derfunc,x0[i],50,tol[j],true)<<endl<<endl;
		}
	}
}