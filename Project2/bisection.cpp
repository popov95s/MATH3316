/* Daniel R. Reynolds
   SMU Mathematics
   Math 3316
   16 September 2015 */

// Inclusions
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "fcn.hpp"

using namespace std;

// This routine uses the bisection method to approximate a root of
// the scalar-valued nonlinear equation f(x)=0 to a solution
// tolerance of tol.
//
// Usage: c = bisection(f, a, b, maxit, tol, show_iterates);
//
// inputs:   f              user-supplied Fcn object
//           a              lower-bound on solution interval [double]
//           b              upper-bound on solution interval [double]
//           maxit          maximum allowed iterations [int]
//           tol            solution tolerance [double]
//           show_iterates  display/hide iteration information [bool]
// outputs:  c              approximate solution [double]
//
double bisection(Fcn& f, double a, double b, int maxit, 
		 double tol, bool show_iterates) {

  // initialize approximate solution
  double c = 0.5*(a+b);

  // check input arguments
  if (maxit < 1) {
    cerr << "warning: maxit = " << maxit << " < 1. Resetting to 100\n";
    maxit = 100;
  }
  if (a >= b) {
    cerr << "error: illegal interval [" << a << ", " << b << "]!\n";
    return 0.0;
  }
  if (tol < 1.e-15) {
    cerr << "warning: tol is too small, resetting to 1e-15\n";
    tol = 1.e-15;
  }

  // get initial function values, check whether root exists in interval
  double fa = f(a);
  double fb = f(b);
  if (fa*fb > 0.0) {
    cerr << "error: illegal interval, f(a)=" << fa << ", f(b)=" << fb << endl;
    return 0.0;
  }
  
  // begin iteration
  double fc, err=0.5*(b-a);
  cout << endl << " Bisection Method: initial |(b-a)/2| = " << err << endl;
  for (int i=0; i<maxit; i++) {
    
    // evaluate function at c
    fc = f(c);
   
    // update interval
    if (fa*fc < 0.0) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }
   
    // compute updated guess, function value
    c = 0.5*(a+b);
   
    // check for convergence and output diagnostics
    err = 0.5*(b-a);
    if (show_iterates) 
      cout << "   iter " << i << ", [" << a << "," << b 
	   << "], |(b-a)/2| = " << err << endl;
    if (err < tol)  break;

  } // end loop

  // return final result
  return c;

} // end of function
