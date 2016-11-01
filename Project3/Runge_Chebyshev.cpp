/*
MATH3316 Project3 
Author: Stefan Popov
Oct 23rd 2016
*/

#include <iostream>
#include <string>
#include <math.h>
#include "matrix.hpp"
#include "Lagrange.cpp"
using namespace std;


void interpolate(int m, int n, string outputFile);

double Lagrange2D(Matrix& x, Matrix& y, Matrix& z, double a, double b);

int main(){
	//declare runge function

	//declare n = m =6
	int n1=6, m1=6;
	int n2=24, m2=24;

	//call interpolate function
	interpolate(n1,m1, "p6_Cheb.txt");
	interpolate(n2,m2, "p24_Cheb.txt");
	
}


//evaluate chebyshevNodes
Matrix chebyshevNodesBuild(int m){
	Matrix x(1,m+1);
	for(int i =0 ;i <m+1; i++){
		x[i][0]= 4*cos((2*(i+1)*M_PI)/(2*m+2));
	}
	return x;
}

void interpolate(int m, int n, string outputFile){
	//declare function
	auto f = [](const double x, const double y) -> double { 
    	return 1/(1+x*x+y*y);
  	};
	
	//create a set of m+1 chebyshev  
	Matrix xNodes = chebyshevNodesBuild(m);

	//create a set of n+1 chebyshev nodes  
	Matrix yNodes = chebyshevNodesBuild(n);

	//create a matrix with dimensions [m+1][n+1] for the function values f(x_i,y_i)
	Matrix fValues(m+1,n+1);
	//fill values for f matrix
	for(int i=0; i<m+1;i++){
		for(int j=0; j<n+1;j++){
			fValues[j][i]=f(xNodes[i][0],yNodes[j][0]);
		}
	}


	//create an array of 201 evenly spaced evaluation points
	Matrix aVals = Linspace(-4,4,1,201);
	//write to disk
	aVals.Write("avals.txt");

	//create an array of 101 evenly spaced evaluation points
	Matrix bVals = Linspace(-4,4,1,101);
	//write to disk
	bVals.Write("bvals.txt");
	


	Matrix p6(201,101);
	//evaluate the polynomial interpolant p(a_i,b_j)
	for( int i = 0 ; i < aVals.Cols(); i++){
		for ( int j=0 ; j<bVals.Cols(); j++){
			p6[j][i] = Lagrange2D(xNodes, yNodes, fValues, aVals[i][0], bVals[j][0]);
		}
	}

	
	//write to file
	p6.Write(outputFile.c_str());

}
double Lagrange2D(Matrix& x, Matrix& y, Matrix& z, double a, double b){
  double result = 0.0;

  for( int i=0; i< x.Rows(); i++){
    for(int j=0; j<y.Rows(); j++){
        result += z(j, i) * Lagrange_basis(x, j, a) * Lagrange_basis(y, i, b);
    }

  }
  return result;

}