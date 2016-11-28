#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "fcn.hpp"
#include "composite_int.cpp"

int m=  10;
int k= 350;
int adaptive_int(Fcn& f, const double a, const double b, const double rtol,
                const double atol, double& R, int& n, int& Ntot){
        
        double tol = rtol * fabs(composite_int(f,a,b,m+k)) + atol;
        double err = fabs(composite_int(f,a,b,m+k) - composite_int(f,a,b,m));

        if( err > tol ){
            Ntot += m+k;
            m *= 2;
            adaptive_int(f, a, b, rtol, atol, R, n, Ntot);
        }
        else{
            R = composite_int(f,a,b,m);
            Ntot += m+k;
            n = m;
        }

}