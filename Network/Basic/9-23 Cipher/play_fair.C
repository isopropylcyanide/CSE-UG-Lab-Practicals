#include <bits/stdc++.h>
#include <iostream>
using namespace std;

static int substitution_index;
char *mat[8];

void build_matrix(string &s1,char ** mat){
	for(int i=0 ; i<8; i++)
		mat[i]= new char[8];

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			mat[i][j]='!';

	set<char> unique;
	for(int i=0; i<s1.size(); i++)
		unique.insert(s1[i]);

	set<char>::iterator sit=unique.begin();
	int last_row,last_col;
	bool over=false;

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			if (sit!=unique.end()){
				mat[i][j]=*sit;
				sit++;
			}
			else{
				last_col=j;
				last_row=i;
				over=true;
				break;
			}
		if (over)break;
	}


	vector<char>not_added_lower;
	for(char x='a'; x<='z'; x++)
		if (find(unique.begin(), unique.end(),x)==unique.end())
			not_added_lower.push_back(x);

	for(int i=0; i<not_added_lower.size(); i++){
		if ((last_col)%8==0){
			last_row+=1;
			last_col=0;
			mat[last_row][last_col++]=not_added_lower[i];
		}
		else mat[last_row][last_col++]=not_added_lower[i];

	}

	vector<char>not_added_upper;
	for(char x='A'; x<='Z'; x++)
		if (find(unique.begin(), unique.end(),x)==unique.end())
			not_added_upper.push_back(x);

	for(int i=0; i<not_added_upper.size(); i++){
		if ((last_col)%8==0){
			last_row+=1;
			last_col=0;
			mat[last_row][last_col++]=not_added_upper[i];
		}
		else mat[last_row][last_col++]=not_added_upper[i];
	}

	for (int i=0; i<10; i++){
		if ((last_col)%8==0){
			last_row+=1;
			last_col=0;
			mat[last_row][last_col++]=i+'0';
		}
		else mat[last_row][last_col++]=i+'0';
	}

	cout<<"\n";
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			cout<<" "<<mat[i][j];
		cout<<endl;
	}
}


char encrypt(char a,char b,vector<char>& output){

	int x1,x2,y1,y2;

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			if (mat[i][j]==a){
				x1=i;
				y1=j;
				break;
			}

	for(int i=0; i<8; i++)
		for(int j=0; j<8; j++)
			if (mat[i][j]==b){
				x2=i;
				y2=j;
				break;
			}

	if (x1==x2){
		output.push_back(mat[x1][(y1+1)%8]);
		output.push_back(mat[x2][(y2+1)%8]);
		output.push_back(' ');
	}

	else if (y1==y2){
		output.push_back(mat[(x1+1)%8][y1]);
		output.push_back(mat[(x2+1)%8][y2]);
		output.push_back(' ');
	}

	else{
		output.push_back(mat[x2][y1]);
		output.push_back(mat[x1][y2]);
		output.push_back(' ');
	}
}

void solve(vector<char> & input_1,vector<char> & input_2){
	vector<char>:: iterator it = input_1.begin();
	vector<char>:: iterator it2 = input_2.begin();
	vector<char> output;

	cout<<"\n The Decrypted Message: ";

	for(;it!=input_1.end();it++,it2++){
		cout<<*it<<*it2<<" ";
		encrypt(*it,*it2,output);
	}

	vector<char>:: iterator ot = output.begin();
	cout<<"\n The Encrypted Message: ";
	for(;ot!=output.end();ot++)
		cout<<*ot;

}


int main(){

	string s1;
	cout<<"\n Enter key string for the matrix: ";
	cin >> s1;

	build_matrix(s1,mat);

	ifstream inf("input.txt");
	char c,i1,i2;
	vector<char>input_1;
	vector<char>input_2;

	while((c=inf.get())!=EOF){

		if(!isalnum(c))
		continue;

		i1=c;
		i2=inf.get();

		while(!isalnum(i2))
			i2=inf.get();

		if(i1==i2){
			input_1.push_back(c);
			input_2.push_back('!');
			input_2.push_back(c);
			input_1.push_back('!');
		}
		else{
			input_1.push_back(i1);
			input_2.push_back(i2);
		}

	}


	inf.close();
	solve(input_1,input_2);
	cout<<endl<<endl;


	return 0;
}
