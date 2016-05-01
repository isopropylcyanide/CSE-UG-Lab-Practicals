#include <bits/stdc++.h>
using namespace std;
static int key, keyInv;

#define SIZE 26

int gcd(int a, int b){
    // Given two numbers, finds GCD using Euclidean Method
    if (a < b)
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

tuple<int, int> extendedGCDUtil(int a, int b, int s1, int s2, int t1, int t2){
    // Util method to find two solutions s1, t1
    if (b == 0)
        return make_tuple(s1, t1);
    return extendedGCDUtil(b, a % b, s2, s1 - (a / b) * s2, t2, t1 - (a / b) * t2);
}

tuple<int, int> extendedGCD(int a, int b){
    // Returns a pair of integers r and s such that a *r + b *s = 1
    // Solutions exist only when gcd(a, b) == 1
    // Let tie (r, s) = extendedGCD(divs[i], mods[i]); then (r + mods[i]) % mods[i] is the mod inv
    if (gcd (a, b) != 1)
        return make_tuple(0,0);
    return extendedGCDUtil(a, b, 1, 0, 0, 1);
}

char encrypt(char c, int key){
	//Encrypt a character given a key
	if (isdigit(c))
		return (c -'0' * key) % 10 + '0';

	else if (isupper(c))
		return char((65 + ((c  - 65) * key) % 26));

	else return char((97 + ((c  - 97) * key) % 26));

}

void solve(string & input){
	//Decrypt the ciphered input when the key is given
	string output;

	for(auto a : input){
		if (isalnum(a))
			output += encrypt(a, key);
		else
			output += a;
		// cout << a << " conv to: " << *output.rbegin() << endl;
	}

	cout<<"\n The Encrypted Message: ";
	cout << output << endl;

	/*Decrypt now*/
	cout<<"\n The Decrypted Message: ";
	for (auto a : output){
		if (isalnum(a))
			cout << encrypt(a, keyInv);
		else
			cout << a;
	}

}


int main(){

	cout << "\n Enter Key(shift): \t";
	cin >> key;
	int b = 0;

	while (gcd(key, SIZE) != 1){
		cout << "\n Key should be coprime to alphabet size";
		cout << "\n Enter Key(shift): \t";
		cin >> key;
	}
	tie(keyInv, b) = extendedGCD(key, SIZE);
	keyInv = (keyInv + SIZE) % SIZE;

	string s;
	cout <<"\n Enter input string: \t";
	cin.ignore();
	getline(cin, s);

	solve(s);
	cout<<endl<<endl;
	return 0;
}
