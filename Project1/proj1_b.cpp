#include "matrix.hpp"
#include <vector>
#include <math.h>
#include <string>
using namespace std;


//forward difference estimate of f'(a)
double plus_fa(double a, double h){
	return (pow((a+h),-3)- pow(a,-3))/h;
}


//returns  -mu1*f(a+h) - mu2*f(a)/ h 
double second_part_of_that_equation(double a, double h){
	const double mu1 = pow(2,-52)/2;
	return (-(mu1*pow(a+h,-3)) - (mu1*pow(a,-3)))/h;  
}

double plus_dp(double a, double h){
	return plus_fa(a,h) + second_part_of_that_equation(a,h);
}

double calculate_r(double a, double h){
	return (-3*(pow(a,-4)) - (plus_dp(a,h)))/(-3*(pow(a,-4)));
}

double calculate_c2(double a){
	const double edp=pow(2,-52);
	return (pow(a,-3)*edp)/(-3*pow(a,-4));
}

double calculate_c1(double a){
	return (-12*pow(a,-5))/(2*(-3)*(pow(a,-4)));
}

double calculate_R(double a, double h){	
	return calculate_c1(a)*h + calculate_c2(a)*(1/h);
}

vector<double> generate_n(){
	vector<double> ns;
	for (double i =1.0 ; i<53.0;i++){
		ns.push_back(i);
	}
	return ns;
}

vector<double> generate_h(vector<double> ns){
	vector<double> hs; 
	for (int i =0 ; i <52; i++){
		hs.push_back(pow(2,-ns[i]));
	}
	return hs;
}

vector<double> generate_r(double x, vector<double> hs){
	vector<double> rs;
	for(int i =0 ; i<hs.size();i++){
		rs.push_back(calculate_r(x,hs[i]));
	}
	return rs;
}

vector<double> generate_R(double x, vector<double> hs){
	vector<double> Rs;
	for(int i =0 ;i<hs.size();i++){
		Rs.push_back(calculate_R(x,hs[i]));
	}
	return Rs;

}

void writeVector(vector<double> wV, string fileName){
	Matrix m(wV);
	m.Write(fileName.c_str());
}

int main(){

	const double a=3;
	vector<double> ns = generate_n();
	vector<double> hs = generate_h(ns);
	vector<double> rs = generate_r(a,hs);
	vector<double> Rs = generate_R(a,hs);


	writeVector(ns, "n.txt");
	writeVector(hs, "h.txt");
	writeVector(rs, "r.txt");
	writeVector(Rs, "R.txt");
}
