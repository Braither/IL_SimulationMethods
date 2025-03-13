#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double x;

	for (x=0.1; x<=10; x+=0.1){
		cout<<x<<"  "<<sin(x)/x<<endl;
	}

	return 0;
}