#include <iostream>

using namespace std;

long long inv(long long a, long long p){
	if(p % a == 0)
		return -1;
	for(int i=1;i<p;i++){
		if( (a*i)%p == 1 )
			return i;
	}
	return -1;
}

long long * add(long long x1, long long y1, long long x2, long long y2, long long A, long long p){
	long long lamda;
	if(x1==x2 && y1==y2){
		if(inv( ((2*y1)%p),p)==-1){
			cout<<"!!!! "<<((2*y1)%p)<<" !!!!"<<endl;
			return NULL;
		}
		lamda = ( (3*x1*x1+A) * inv(2*y1,p) ) % p;
	}else{
		long long top = (y2 >= y1)? y2-y1 : y2-y1+p;
		long long btm = (x2 >= x1)? x2-x1 : x2-x1+p;
		if(inv(btm,p)== -1){
			cout<<"!!!!! "<<btm<<" !!!!!"<<endl;
			return NULL;
		}
		lamda = ( top * inv(btm,p) ) % p;
	}

	long long x3=(lamda*lamda-x1-x2)%p;
	while(x3<0){
		x3+=p;
	}
	x3 = x3%p;

	long long y3=(lamda*(x1-x3)-y1)%p;
	while(y3<0){
		y3+=p;
	}
	y3=y3%p;

	long long *re = new long long [2];
	re[0]=x3;
	re[1]=y3;
	return re;
}

int main(){
	long long px,py,A,B,p;

	while(1){
		cout<<"input px py A B p"<<endl;
		cin>>px;
		cin>>py;
		cin>>A;
		cin>>B;
		cin>>p;
		long long nowx = px, nowy = py;
		long long* temp;
		int count = 0;
		while(1){
			temp = add(nowx, nowy, px, py, A, p);
			cout<<"#"<<count++<<" ("<<nowx<<" , "<<nowy<<" )"<<endl;
			if(temp == NULL)
				break;
			else{
				nowx = temp[0];
				nowy = temp[1];
				delete temp;
			} 
		}
	}
}