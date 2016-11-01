/*
MATH3316 Project3 
Author: Stefan Popov
Oct 23rd 2016
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"

using namespace std;
/*Provided by Daniel Reynolds*/
// Utility function to evaluate a given Lagrange basis function at a point, phi_i(z).
//
// Usage: l = Lagrange_basis(x, i, z);
//
// inputs:   x     Matrix of length n+1, containing the interpolation nodes
//           i     integer indicating which Lagrange basis function to evaluate
//           z     double location to evaluate basis function
// outputs:  p     value of phi_i(z)
// 
double Lagrange_basis(Matrix& x, int i, double z) {
  double l = 1.0;              // initialize basis function
  for (size_t j=0; j<x.Size(); j++)
     if (j != i)
       l *= (z - x(j)) / (x(i) - x(j));
  return l;
}

//Lagrange2D evaluates the 2D Lagrange given the input matrices x,y,z and coefficients a and b

double Lagrange2D(Matrix& x, Matrix& y, Matrix& z, double a, double b){
  double result = 0.0;

  for( int i=0; i< x.Rows(); i++){
    for(int j=0; j<y.Rows(); j++){
        result += z(j, i) * Lagrange_basis(x, j, a) * Lagrange_basis(y, i, b);
    }

  }
  return result;
}


