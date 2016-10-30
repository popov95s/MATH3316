#include <iostream>
#include "matrix.hpp"
#include <vector>
#include "fcn.hpp"
using namespace std;
vector<double> as;
    
class fcn : public Fcn {
public:
  double operator()(double x) {   // function evaluation
    return (3.1*x*x*x*x + 2.3*x*x*x - 6.6*x*x + 8.7*x + 7.9);
  }
};


double Newton_basis(Matrix& xnodes, int n, double x);
double Newton_nestedform(Matrix& a, Matrix& xnodes, double x);
Matrix Newton_coefficients(Matrix& xnodes, Matrix& ynodes);
int main(){
    fcn f;
    vector<double> xi= {-2,-1,0,1,2};
    vector<double> yi;
    for ( int i=0; i<5; i++){
        yi.push_back( f(xi[i]));
    }
    Matrix xis(xi);
    Matrix yis(yi);
    Matrix aMatrix= Newton_coefficients(xis,yis);
    Matrix xValues= Linspace(-3,3,1,201);
    vector<double> xInterpolated;
    vector<double> fxs;
    vector<double> errorVector;
    for ( int i=0 ;i < xValues.Cols();i++){
        double xInter =Newton_nestedform(aMatrix,xis,xValues[i][0]);
        xInterpolated.push_back(xInter);
        double fx = f(xValues[i][0]);
        fxs.push_back(fx);
        errorVector.push_back(fx-xInter);
    }
    Matrix xInterpol(xInterpolated);
    Matrix fxMatrix(fxs);
    Matrix errorMatrix(errorVector);
    xInterpol.Write("xInterpol.txt");
    fxMatrix.Write("y.txt");
    errorMatrix.Write("error.txt");
    xValues.Write("x.txt");
    return 0;
}

double Newton_basis(Matrix& xnodes, int n, double x){
    double phi= 1.0;
    for(int i=0 ; i < n; i++){
        phi*= (x-xnodes[0][i]);
    }
    return phi;
}

double Newton_nestedform(Matrix& a, Matrix& xnodes, double x){
    double pnOfX=0.0;

    for(int i= 0 ; i< a.Rows(); i++){
        pnOfX+=Newton_basis(xnodes,i, x)*a[0][i];
    }
    return pnOfX;
}
Matrix Newton_coefficients(Matrix& xnodes, Matrix& ynodes){
    for(int i = 0; i< xnodes.Rows(); i++){
        Matrix asTemp(as);
        double firstPart = ynodes[0][i] - Newton_nestedform(asTemp,xnodes, xnodes[0][i]);
        double secondPart =(Newton_basis(xnodes,i,xnodes[0][i]));
        as.push_back((firstPart)/secondPart);
    }
    Matrix aMatrix(as);
    return aMatrix;
}
