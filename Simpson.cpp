#include <iostream>
#include <cmath>
using namespace std;

const double ErrMax = 1e-7;

double f(double x){
	return cos(x);
}

double IntegralSimpson(double a, double b, int n){
	double x, h, sum;
	int i;
	n *= 2;
	h =(b-a)/n;
	for(sum=0, i=0; i<=n; i++){
		x = a + i*h;
		if(i == 0 || i == n){sum += f(x);} //Si es primero o ultimo, sumar 1 vez
		else if(i%2 == 0){sum += 2*f(x);} 	//Si es par, sumar 2 veces
		else{sum += 4*f(x);} 				//Si es impar, sumar 4 veces
	}
	return sum*h/3;
}

int main(){
	double a=0, b=M_PI/2+1;
	int n = 50;
	cout<<"La integral es: "<<IntegralSimpson(a, b, n)<<endl;
}