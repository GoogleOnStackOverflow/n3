#include <iostream>

using namespace std;

long long* xa (int a, long long h, long long g, long long p){
	long long x = 1, al = 0, be = 0;
	for(int i=0;i<a;i++){
		if(x<p/3){
			x = (x*h) % p;
			al = (al + 1) % (p - 1);
		}else if(x>=p/3 && x<2*p/3){
			x = (x*x) % p;
			al = (al * 2) % (p - 1);
			be = (be * 2) % (p - 1);
		}else{
			x = (x*g) % p;
			be = (be + 1) % (p - 1);
		}
	}
	long long * re = new long long [3];
	re[0]=x;
	re[1]=al;
	re[2]=be;
	return re;
}

long long gcd(long long a, long long b){
	long long temp = (a>b)?b:a;
	while(temp>1){
		if(b%temp == 0 && a%temp == 0)
			return temp;
		temp--;
	}

	return 1;
}

long long find_mul(long long a, long long b, long long p){
	for(long long i=0; i<p; i++){
		if((i*a)%p == b){
			cout<<a<<" x "<<i<<" = "<<b<<" ( mod "<<p<<" )"<<endl;
			return i;
		}
	}

	throw;
}

int main () {
	while(1){
		long long h1,g1,p1;
		long long *temp1;
		long long *temp2;

		cout<<"enter h, g, p"<<endl;
		cin>>h1;
		cin>>g1;
		cin>>p1;
		int count = 1;
		const long long h = h1, g = g1, p = p1;

		cout<<"count\t|xi\t|x2i\t|alpha\t|beta\t|gama\t|delta"<<endl;
		do{
			temp1 = xa(count,h,g,p);
			temp2 = xa(count*2,h,g,p);
			cout<<count<<"\t"<<temp1[0]<<"\t"<<temp2[0]<<"\t"<<temp1[1]<<"\t"<<temp1[2]<<"\t"<<temp2[1]<<"\t"<<temp2[2]<<endl;
			count++;
		}
		while(temp1[0]!=temp2[0]);

		cout<<"Match Found!"<<endl;

		long long alp = temp1[1]-temp2[1];
		long long bet = temp2[2]-temp1[2];
		alp = (alp>0) ? alp : (alp + (p-1));
		bet = (bet>0) ? bet : (bet + (p-1));
		cout<< h <<" ^ "<<alp<<" = "<<g<<" ^ "<<bet<<" = "<<temp1[0]<<" ( mod "<<p<<" )"<<endl;
		long long tar = gcd(bet, (p-1));
		cout<<"gcd( "<<bet<<" , "<<(p-1)<<" ) = "<<tar<<endl;

		long long to_mul1 = find_mul(bet,tar,(p-1));
		long long to_mul = ((to_mul1 * alp) % (p-1))/tar;
		long long * to_exp = new long long [(p - to_mul)/((p-1)/tar)+2];

		long long to_push = 0;
		count = 0;
		while(to_push < p){
			to_push = to_mul + (count * ((p-1)/tar));
			to_exp[count] = to_push;
			count++;
		}


		for(int i=0, j=(p - to_mul)/((p-1)/tar)+1; i<j; i++){
			long long btm = 1;
			for(long long q=0; q<to_exp[i]; q++){
		    	btm = (btm * h) % p;
			}

			btm = btm % p;
			cout<<h<<" ^ " << to_exp[i] <<" = "<<btm<<" ( mod "<<p<<" )"<<endl;
			if( btm == g ){
				cout<<"Got!! x = "<<to_exp[i]<<endl;
				break;
			}
		}
	}
}