#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"
#include "adaptive_int.cpp"
// Integrand
class fcn : public Fcn {
public:
  double c, d;
  double operator()(double x) {   // function evaluation
    return (exp(c*x) + sin(d*x));
  }
  double antiderivative(double x) { // function evaluation
    return (exp(c*x)/c - cos(d*x)/d);
  }
};

int main(){
// limits of integration
  double a = -3.0;
  double b = 5.0;

  // integrand
  fcn f;
  f.c = 0.5;
  f.d = 25.0;

  // true integral value
  double Itrue = f.antiderivative(b) - f.antiderivative(a);
  double rtol_exps[6] = {2,4,6,8,10,12};
  vector<double> rtols;
  for (int i=0; i<6; i++){
    rtols.push_back(1/pow(10,rtol_exps[i]));
  }
  vector<double> errors;

  for (int i=0; i<6; i++){
    //excepted tolerance
    double rtol = rtols[i];
    double atol = rtol/(1000);
    double tolerance = rtol* fabs(Itrue) + atol;

    printf("\n\tTrue Integral = %22.16e\n", Itrue);
    printf("\tTolerance = %7.1e\n", tolerance);


    // test the Gauss-4 rule
    cout << "\n adaptive solver:\n";
    cout << "     n             R(f)            relerr      Ntot\n";
    cout << "  ---------------------------------------------------\n";

    // iterate over n values, computing approximations, error, convergence rate
    double Iapprox; //integral estimation
    int Ntot; //number of intervals tried
    int n;    //final number of intervals used

    //call adaptive solver
    adaptive_int(f, a, b, rtol, atol, Iapprox, n, Ntot);

    errors.push_back(fabs(Itrue-Iapprox)/fabs(Itrue));
    printf("    %d\t  %22.12e  %7.1e       %d\n", n, Iapprox, errors[i], Ntot);


    cout << "  ---------------------------------------------------\n";
  }
}