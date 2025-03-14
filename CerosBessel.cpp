#include <iostream>
#include <cmath>
using namespace std;

const double ErrMax = 1e-7;

double f(double x, double t, double alpha){
	return cos(alpha*t - x*sin(t));
}

double IntegralSimpson(double a, double b, int n, double x, double alpha){
	double t, h, sum;
	int i;
	n *= 2;
	h =(b-a)/n;
	for(sum=0, i=0; i<=n; i++){
		t = a + i*h;
		if(i == 0 || i == n){sum += f(x, t, alpha);} //Si es primero o ultimo, sumar 1 vez
		else if(i%2 == 0){sum += 2*f(x, t, alpha);} 	//Si es par, sumar 2 veces
		else{sum += 4*f(x, t, alpha);} 				//Si es impar, sumar 4 veces
	}
	return sum*h/3;
}

double Bessel(double x, double alpha){
	double a=0, b=M_PI;
	int n = 50;
	return IntegralSimpson(a, b, n, x, alpha)/M_PI;
}

double CerosPorBiseccion(double a, double b, double alpha){
	double m, f_a, f_m;
	f_a = Bessel(a, alpha);
	while(b-a>ErrMax){
		m = (a + b)/2; //Mitad del intervalo
		f_m = Bessel(m, alpha); 
		if(f_a*f_m > 0){a = m; f_a = f_m;} //Si son del mismo signo correr a hasta m
		else{b = m;} //En caso contrario correr b hasta m
	}
	return (a+b)/2;
}

int main(){
	double alpha=0;
	double a=2, b=4;
	/*for(x=0; x<=10; x+=0.1){
		cout<<x<<"		"<<Bessel(x, alpha)<<endl;
	}*/
	
	cout<<"Para Bessel con Alpha=	"<<alpha<<"	El cero es en: "<<CerosPorBiseccion(a, b, alpha)<<endl;
}