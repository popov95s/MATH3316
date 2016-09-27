/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   16 September 2015 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// Bisection solver prototype
double bisection(Fcn& f, double a, double b, int maxit, 
		 double tol,bool show_iterates);

// Root-finding residual function
class fcn : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (10.0 + x*x*x - 12.0*cos(x));
  }
};


// This routine tests the function bisection.cpp on a nonlinear 
// function.  It uses an initial interval [-5,5], and solves for 
// the root to a tolerance of 1e-4. 
int main(int argc, char* argv[]) {

  // set the initial interval, max iteration count, and the tolerance
  double a = -5.0; 
  double b = 5.0;
  int maxit = 1000000;
  double tol = 1e-5;

  // create the function object
  fcn f;

  // call bisection to compute the root, and output result to screen
  double x = bisection(f, a, b, maxit, tol, true);
  cout << endl << " The approximate root is " << setprecision(16) 
       << x << endl;

}
