#include <iostream>

using namespace std;

long long to_the(long long a, long long b, long long p){
	long long temp = 1;
	for(long long i=0;i<b;i++){
		temp = (temp * a) % p;
	}

	return temp;
}

int main(){
	long long a,b,p;
	cin>> a;
	cin>> b;
	cin>> p;

	for(long long i=1;i<p;i++){
		if(to_the(a,i,p) == b)
			cout<<"Got x = "<<i<<" !"<<endl;
	}

	return 0;
}