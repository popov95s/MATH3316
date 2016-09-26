#include <iostream>
#include <vector>
#include <math.h>
#include "matrix.hpp"
using namespace std;


Matrix createVandermonde(Matrix& v){
	vector<vector<double>> vandermonde;
	vector<double> temp;
	for(int i=0; i<v.Cols(); i++){
		for(int j=0; j<v.Cols(); j++){
			temp.push_back(pow(v[0][i],j));
		vandermonde.push_back(temp);
		temp.clear();
	}
	return Matrix(vandermonde);
}

vector<double> getVector(Matrix& x){
	vector<double> returnVec;
	for(int i=0; i<x.Cols(); i++){
		returnVec.push_back(x[0][i]);
	}
	return returnVec;
	
}

int main(){
	

	double n[5]= {5,9,17,33,65};
	
	Matrix v1 = Linspace(-1.0, 1.0, 1, (size_t)n[0]);
	Matrix v2 = Linspace(-1.0, 1.0, 1, (size_t)n[1]);
	Matrix v3 = Linspace(-1.0, 1.0, 1, (size_t)n[2]);
	Matrix v4 = Linspace(-1.0, 1.0, 1, (size_t)n[3]);
	Matrix v5 = Linspace(-1.0, 1.0, 1, (size_t)n[4]);
	
	Matrix x1 = Random(1, (size_t)n[0]);
	Matrix x2 = Random(1, (size_t)n[1]);
	Matrix x3 = Random(1, (size_t)n[2]);
	Matrix x4 = Random(1, (size_t)n[3]);
	Matrix x5 = Random(1, (size_t)n[4]);
	
	Matrix b1 = x1*createVandermonde(v1);
	Matrix b2 = x2*createVandermonde(v2);
	Matrix b3 = x3*createVandermonde(v3);
	Matrix b4 = x4*createVandermonde(v4);
	Matrix b5 = x5*createVandermonde(v5);
	
	
	Matrix x1Hat = Solve(x1*createVandermonde(v1));
	Matrix x2Hat = Solve(x2*createVandermonde(v2));
	Matrix x3Hat = Solve(x3*createVandermonde(v3));
	Matrix x4Hat = Solve(x4*createVandermonde(v4));
	Matrix x5Hat = Solve(x5*createVandermonde(v5));
	
	vector<double> error1Vector = getVector(x1Hat- x1);
	vector<double> error2Vector = getVector(x2Hat- x2);
	vector<double> error3Vector = getVector(x3Hat- x3);
	vector<double> error4Vector = getVector(x4Hat- x4);
	vector<double> error5Vector = getVector(x5Hat- x5);
	
	
	double twoNorm1 = Norm(error1Vector);
	double twoNorm2 = Norm(error2Vector);
	double twoNorm3 = Norm(error3Vector);
	double twoNorm4 = Norm(error4Vector);
	double twoNorm5 = Norm(error5Vector);
	
	vector<double> residual1 = getVector(createVandermonde(v1)*x1Hat - b1);
	vector<double> residual2 = getVector(createVandermonde(v2)*x2Hat - b2);
	vector<double> residual3 = getVector(createVandermonde(v3)*x3Hat - b3);
	vector<double> residual4 = getVector(createVandermonde(v4)*x4Hat - b4);
	vector<double> residual5 = getVector(createVandermonde(v5)*x5Hat - b5);
	
	cout<<twoNorm1<<" "<<residual1<<endl;
	cout<<twoNorm2<<" "<<residual2<<endl;
	cout<<twoNorm3<<" "<<residual3<<endl;
	cout<<twoNorm4<<" "<<residual4<<endl;
	cout<<twoNorm5<<" "<<residual5<<endl;
	return 0;
}
