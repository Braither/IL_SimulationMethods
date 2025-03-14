#include <iostream>
#include <cmath>
using namespace std;

const double ErrMax = 1e-7;

double f(double x){
	return sin(x)/x;
}

double CerosPorBiseccion(double a, double b){
	double m, f_a, f_m;
	f_a = f(a);
	while(b-a>ErrMax){
		m = (a + b)/2; //Mitad del intervalo
		f_m = f(m); 

		if(f_a*f_m > 0){a = m; f_a = f_m;} //Si son del mismo signo correr a hasta m
		else{b = m;} //En caso contrario correr b hasta m
	}
	return (a+b)/2;
}

int main(){
	double a = 2, b = 4;
	cout<<"El cero es "<<CerosPorBiseccion(a, b)<<endl;
	return 0;
}