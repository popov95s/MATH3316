#include "matrix.hpp"

using namespace std;

double nest(Matrix& a, double x){


	int n = a.Cols();
	double p=0;

	p=  a[n][0];

	for( int i = n-1 ; i>=0; i--){
		p = a[i][0] + x*(p);
	}
	cout<<" Yay";
	return 2.0;
}