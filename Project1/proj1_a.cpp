
#include <iostream>
#include <vector>
#include "nest.cpp"
#include <math.h>
#include <string>

using namespace std;

Matrix getCoefficients(int n);

//simple factorial function
int factorial(int x, int result = 1) {
  if (x == 1 || x == 0) return result; else return factorial(x - 1, x * result);
}

void evaluateAndWritePolynomials(Matrix,int);
void evaluateExponential(Matrix);
int main(){
	
	size_t size = 201;
	Matrix z = Linspace(-1.0, 1.0, 1,size);

	z.Write("z.txt");
	evaluateAndWritePolynomials(z,4);
	evaluateAndWritePolynomials(z,8);
	evaluateAndWritePolynomials(z,12);

	evaluateExponential(z);

}

void evaluateExponential(Matrix z){
	vector<double> results;
	for (int i =0 ;i <z.Cols(); i++){
		results.push_back(exp(z[i][0]));
	}
	Matrix expFinal = Matrix(1,z.Cols(),results);
	expFinal.Write("f.txt");
}

void evaluateAndWritePolynomials(Matrix z, int pDegree){

	Matrix coefficients = getCoefficients(pDegree);

	vector<double> results;
	vector<double> errors;
	for ( int i = 0 ; i< z.Cols(); i++){
		double p =nest(coefficients,z[i][0]);
		results.push_back(p);
		errors.push_back(abs(exp(z[i][0])-p));
	}

	Matrix errorFinal = Matrix( 1, z.Cols(), errors);
	Matrix pFinal = Matrix(1,z.Cols(),results);

	string textFile = "p" + to_string(pDegree)+".txt";
	string errorFile = "err"+  to_string(pDegree) + ".txt";

	pFinal.Write(textFile.c_str());
	errorFinal.Write(errorFile.c_str());

}


Matrix getCoefficients(int n){
	vector<double> coeffs;

	for (int i =0 ; i<n ; i++){
		coeffs.push_back(1.0/factorial(i));
	}


	Matrix ret = Matrix(1,n, coeffs);


	return ret;

}

