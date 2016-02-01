#include <bits/stdc++.h>
using namespace std;

typedef long long int llu;

inline llu gcd(llu a , llu b){
	if (a % b == 0)
		return b;

	else return gcd(b,a%b);
}

llu power_exp(llu a,llu p,llu MOD)
{
    llu RES = 1;
    llu B = (llu) a;
    while(p > 0)
    {
        if(p%2 == 1) RES = (RES*B)%MOD;
        B = (B*B)%MOD;
        p = p/2;
    }
    llu res = (llu) RES;
    return res;
}


llu compute_d(llu e, llu z){

	llu d = 1;
	bool count= true;
	
	while(count){
		d+=1;
		if ((e*d) % z == 1)
			count=false;
	}

	return d;
}

bool isCoprime(llu &a, llu &b){
	set<llu>factor_a;

	for(llu i = 1 ; i<=sqrt(a); i++)
		if (a % i == 0){
			factor_a.insert(i);
			factor_a.insert(a/i);
		}

	set<llu> :: iterator si = factor_a.begin();
	for(; si!=factor_a.end(); si++)
		if (b % *si ==0 && *si != 1)
			return false;

	return true;
}

inline llu encrypt(llu input, llu e , llu n){
	llu enc = power_exp(input, e, n);
	cout<<"\n Encrypted "<<input<<" as "<<enc;
	return enc;
}

inline llu decrypt(llu cipher, llu d, llu n){
	llu dec = power_exp(cipher, d, n);
	cout<<"\n Decrypted "<<cipher<<" as "<<dec;
}


int main(){

	llu a,b,e = 1;
	llu input;

	cout <<"\nEnter two space separated lluegers: ";
	cin >> a >> b;

	assert (isCoprime(a,b));

	llu n = a*b , z =  (a-1) * (b-1);
	cout <<"\n N: "<< n;
	cout <<"\n Z: " << z;

	while(++e){
		if(e<z){
			if(gcd(z,e)==1)
				break;
		}
		else{
			if(gcd(e,z)==1)
				break;
		}
	}

	llu d = compute_d(e,z);
	cout <<"\n E: " << e;
	cout <<"\n D: " << d;


	cout << "\n\n Public Key: (" << e << "," << n << ")";
	cout << "\n Private Key: (" << d << "," << n << ")"<<endl;

	while(true){
		cout<<"\n\n Enter confidential text : "; cin>>input;
		llu enc = encrypt(input, e, n);
		decrypt(enc, d, n);
	}

	return 0;
}