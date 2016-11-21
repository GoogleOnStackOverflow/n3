#include <iostream>

using namespace std;

int main(){
	double temp = 1.0;
	while(1){
		double a;
		cin>>a;
		for(double i=0; i<a ;i++){
			temp *= (365.0-i)/365.0;
		}
		cout<<"prob = "<< (1.0 - temp)<<endl;
		temp = 1.0;
	}

	return 0;
}