#include "matrix.hpp"

using namespace std;

double nest(Matrix& a, double x){


	int n = a.Cols();
	double p=0;

	p=  a[n-1][0];

	for( int i = n-2 ; i>=0; i--){
		p = a[i][0] + x*(p);
	}

	return p;
}