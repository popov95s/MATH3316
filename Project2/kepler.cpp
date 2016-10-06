/*
MATH3316 Project2 
Author: Stefan Popov
Oct 5th 2016
*/
#include <iostream>
#include "matrix.hpp"
#include <math.h>
#include <vector>
#include "newton.cpp"

using namespace std;

class fcn: public Fcn{
public:
  	double operator()(double x) {   // function evaluation
  	 	return x - epsilon*sin(x)  - t;
  	}
  	void setT(double t){
  		this->t=t;
  	}
 private:

	const double a = 2.0;
	const double b = 1.25;
	double epsilon = sqrt(1-(b*b)/(a*a));
	double t;
};

class derfcn: public Fcn{
public:
	double operator()(double x) {   // function evaluation
	    return 1 - epsilon*cos(x) ;
	}
private:	
	const double a = 2.0;
	const double b = 1.25;
	double epsilon = sqrt(1-(b*b)/(a*a));
};



int main(){
	//declare function and derivative
	fcn f;
	derfcn df;

	//declare tolerance, iterations coutn and iterates
	const double tolerance = pow(10.0,-5.0);
	const bool show_iterates = false;
	const int iterations = 6;

	//declare a, b and derive epsilon
	const double a = 2.0;
	const double b = 1.25;
	double epsilon = sqrt(1-(b*b)/(a*a));

	//declare the initial w and the Linspace of t
	double w = 0.0;
	Matrix ts = Linspace(0,10,1,(size_t)10000);

	//declare a vector of double to store results from the newton method
	vector<double> ws;

	//loop over all values of t, reset t in the function class and push the result of Newton's method to the vector of results. Reset w
	for( int i =0 ; i<ts.Cols();i++){
		f.setT(ts[i][0]);
		ws.push_back(newton(f,df,w,  iterations, tolerance,show_iterates));
		w = ts[i][0];
	}
	//convert x and y coordinates to radial 
	vector<double> cartesianxs;
	vector<double> cartesianys;
	double r;

	//iterate over all values of w, compute r and the cartesian coordinates and 
	for( int i = 0 ; i < ws.size(); i++){

		r = (a*b) / (sqrt( pow(b * cos(ws[i]),2) + pow(a * sin(ws[i]),2) ));


		cartesianxs.push_back(r*cos(ws[i]));
		cartesianys.push_back(r*sin(ws[i]));

	} 
	
	//create matrix from vector 
	Matrix xs(cartesianxs);
	Matrix ys(cartesianys);

	//write to file

	xs.Write("x.txt");
	ys.Write("y.txt");
	ts.Write("t.txt");



}