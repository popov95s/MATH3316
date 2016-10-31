#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "matrix.hpp"

using namespace std;

//Lagrange2D evaluates 

double Lagrange2D(Matrix& x, Matrix& y, Matrix& z, double a, double b){
  double result = 0.0;

  for( int i=0; i< x.Rows(); i++){
    for(int j=0; j<y.Rows(); j++){
        result += z(j, i) * Lagrange_basis(x, j, a) * Lagrange_basis(y, i, b);
    }

  }
  return result;
}