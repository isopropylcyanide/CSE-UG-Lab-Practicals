#include <bits/stdc++.h>
using namespace std;
static int key;


char encrypt(char c){
	//Encrypt a character given a key
	if (isdigit(c))
		return (c -'0' +key)%10 + '0';

	else if (isupper(c))
		return char((65 + (int(c)  - 65 +key)%26 ));

	else return char((97 + (int(c)  - 97 +key)%26 ));

}

void solve(vector<char> & input){
	//Decrypt the ciphered input when the key is given
	vector<char>:: iterator it = input.begin();
	vector<char> output;

	cout<<"\n The Decrypted Message: ";

	for(;it!=input.end();it++){
		cout<<*it;

		if (isalnum(*it))
			output.push_back(encrypt(*it));
		else
			output.push_back(*it);
	}

	vector<char>:: iterator ot = output.begin();
	cout<<"\n The Encrypted Message: ";
	for(;ot!=output.end();ot++)
		cout<<*ot;

}


int main(){

	cout << "\n Enter Key(shift): \t";
	cin >> key;

	string s;
	cout <<"\n Enter input string: \t";
	cin.ignore();
	getline(cin, s);
	vector<char>input (s.begin(), s.end());

	solve(input);
	cout<<endl<<endl;
	return 0;
}
