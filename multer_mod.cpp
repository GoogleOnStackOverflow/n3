#include <iostream>

using namespace std;

int main(){
	while(1){
		long long a,b,p;
		cin>>a;
		cout<<"x X = "<<endl;
		cin>>b;
		cout<<"%"<<endl;
		cin>>p;

		for(long long i=0; i<p; i++){
			if((i*a)%p == b){
				cout<<"X = "<<i<<endl;
			}
		}
	}
}