#include <iostream>
#include <cmath>
using namespace std;

const double ErrMax = 1e-7;

double f(double x){
	return sin(x)/x;
}

int main(){

	double x;
	double a=2, b=4, m, f_a, f_m;
	f_a = f(a);

	while(b-a>ErrMax){
		m = (a + b)/2;
		f_m = f(m);
		if(f_a*f_m > 0){a = m; f_a = f_m;}
		else{b = m;}
	}
	cout<<"El cero es "<<(a+b)/2<<endl;
	return 0;
}