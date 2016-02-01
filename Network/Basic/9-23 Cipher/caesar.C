#include <bits/stdc++.h>
using namespace std;
static int substitution_index;


char encrypt(char c){
	
	if (isdigit(c))
		return (c -'0' +substitution_index)%10 + '0';

	else if (isupper(c))
		return char((65 + (int(c)  - 65 +substitution_index)%26 ));

	else return char((97 + (int(c)  - 97 +substitution_index)%26 ));

}

void solve(vector<char> & input){
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

	substitution_index=3;

	ifstream inf("input.txt");
	char c;
	vector<char>input;

	while((c=inf.get())!=EOF)
		input.push_back(c);

	inf.close();
	solve(input);
	cout<<endl;


	return 0;
}