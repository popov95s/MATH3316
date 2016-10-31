/*
MATH3316 Project3 
Author: Stefan Popov
Oct 23rd 2016
*/
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
    //declare f 
    fcn f;
    //declare xi vector
    vector<double> xi= {-2,-1,0,1,2};
    //declare and evaluate yi
    vector<double> yi;
    for ( int i=0; i<5; i++){
        yi.push_back( f(xi[i]));
    }
    //construct matrix with the above vectors
    Matrix xis(xi);
    Matrix yis(yi);

    //construct matrix of coefficients by calling the Newton_coefficients method
    Matrix aMatrix= Newton_coefficients(xis,yis);

    //construct the xValues by creating a Matrix of equally spaced doubles from -3 to 3
    Matrix xValues= Linspace(-3,3,1,201);

    //declare vectors 
    vector<double> xInterpolated;
    vector<double> fxs;
    vector<double> errorVector;

    //fill the xInterpolated vector with corresponding value and 
    //fill f(x) vector and the error vector accordingly
    for ( int i=0 ;i < xValues.Cols();i++){
        double xInter =Newton_nestedform(aMatrix,xis,xValues[i][0]);
        xInterpolated.push_back(xInter);
        double fx = f(xValues[i][0]);
        fxs.push_back(fx);
        errorVector.push_back(fx-xInter);
    }

    //convert vectors to matrices and write to file
    Matrix xInterpol(xInterpolated);
    Matrix fxMatrix(fxs);
    Matrix errorMatrix(errorVector);
    xInterpol.Write("xInterpol.txt");
    fxMatrix.Write("y.txt");
    errorMatrix.Write("error.txt");
    xValues.Write("x.txt");
    return 0;
}

//Newton_basis function accepts the xNodes, an integer n and 
//the double x. It returns the newton basis by simply iterating 
//over the xNodes matrix and evaluating at each point
double Newton_basis(Matrix& xnodes, int n, double x){
    double phi= 1.0;
    for(int i=0 ; i < n; i++){
        phi*= (x-xnodes[0][i]);
    }
    return phi;
}

//Newton_nestedform accepts the coefficients matrix a, the 
//x nodes matrix and a double x. It returns the evaluation of p_n(x)
//by calling the Newton_basis function and multiplying by the 
//corresponding coefficient in the a matrix
double Newton_nestedform(Matrix& a, Matrix& xnodes, double x){
    double pnOfX=0.0;

    for(int i= 0 ; i< a.Rows(); i++){
        pnOfX+=Newton_basis(xnodes,i, x)*a[0][i];
    }
    return pnOfX;
}
//Newton_coefficients method accepts the x and y nodes and returns the updates the coefficients matrix
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
