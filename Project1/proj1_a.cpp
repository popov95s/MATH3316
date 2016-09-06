
#include <iostream>
#include <vector>
#include "nest.cpp"

using namespace std;

Matrix getCoefficients(int n);

//simple factorial function
int factorial(int x, int result = 1) {
  if (x == 1) return result; else return factorial(x - 1, x * result);
}

int main(){
	
	size_t size = 201;
	Matrix x = Linspace(-1.0, 1.0, 1,size);
	
	Matrix a = getCoefficients(4);
	cout<<a;

	double b = nest(a, 1);
	cout<<b;
}


Matrix getCoefficients(int n){
	vector<double> coeffs;

	for (int i =1 ; i<=n ; i++){
		coeffs.push_back(1.0/factorial(i));
	}

	Matrix ret = Matrix(1,n, coeffs);


	return ret;

}

