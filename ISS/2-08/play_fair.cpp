#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAT_SIZE 8
#define inputFile "input.txt"
char * mat[MAT_SIZE];

void build_matrix(string &s1, char ** mat){
	for(int i = 0 ; i<MAT_SIZE; i++)
		mat[i]= new char[MAT_SIZE];

	for(int i = 0; i<MAT_SIZE; i++)
		for(int j = 0; j<MAT_SIZE; j++)
			mat[i][j] = '!';

	set<char> unique;
	for(int i = 0; i<s1.size(); i++)
		unique.insert(s1[i]);

	set<char>::iterator sit = unique.begin();
	int last_row, last_col;
	bool over = false;

	for(int i = 0; i<MAT_SIZE; i++){
		for(int j = 0; j<MAT_SIZE; j++)
			if (sit != unique.end()){
				mat[i][j] = *sit;
				sit++;
			}
			else{
				last_col = j;
				last_row = i;
				over = true;
				break;
			}
		if (over)break;
	}


	vector<char>not_added_lower;
	for(char x = 'a'; x <= 'z'; x++)
		if (find(unique.begin(), unique.end(), x) == unique.end())
			not_added_lower.push_back(x);

	for(int i = 0; i<not_added_lower.size(); i++){
		if ((last_col) % MAT_SIZE == 0){
			last_row += 1;
			last_col = 0;
			mat[last_row][last_col++] = not_added_lower[i];
		}
		else mat[last_row][last_col++] = not_added_lower[i];

	}

	vector<char>not_added_upper;
	for(char x = 'A'; x <= 'Z'; x++)
		if (find(unique.begin(), unique.end(), x) == unique.end())
			not_added_upper.push_back(x);

	for(int i = 0; i<not_added_upper.size(); i++){
		if ((last_col) % MAT_SIZE == 0){
			last_row += 1;
			last_col = 0;
			mat[last_row][last_col++] = not_added_upper[i];
		}
		else mat[last_row][last_col++] = not_added_upper[i];
	}

	for (int i = 0; i<10; i++){
		if ((last_col) % MAT_SIZE == 0){
			last_row += 1;
			last_col = 0;
			mat[last_row][last_col++] = i+'0';
		}
		else mat[last_row][last_col++] = i+'0';
	}

	cout << "\n";
	for(int i = 0; i<MAT_SIZE; i++){
		for(int j = 0; j<MAT_SIZE; j++)
			cout << " " << mat[i][j];
		cout << endl;
	}
}


void encrypt(char a, char b, vector<char>& outputA, vector<char>& outputB){
	int x1, x2, y1, y2;

	for(int i = 0; i<MAT_SIZE; i++)
		for(int j = 0; j<MAT_SIZE; j++)
			if (mat[i][j] == a){
				x1 = i;
				y1 = j;
				break;
			}

	for(int i = 0; i<MAT_SIZE; i++)
		for(int j = 0; j<MAT_SIZE; j++)
			if (mat[i][j] == b){
				x2 = i;
				y2 = j;
				break;
			}

	if (x1 == x2){
		outputA.push_back(mat[x1][(y1+1) % MAT_SIZE]);
		outputB.push_back(mat[x2][(y2+1) % MAT_SIZE]);
	}

	else if (y1 == y2){
		outputA.push_back(mat[(x1+1) % MAT_SIZE][y1]);
		outputB.push_back(mat[(x2+1) % MAT_SIZE][y2]);
	}

	else{
		outputA.push_back(mat[x2][y1]);
		outputB.push_back(mat[x1][y2]);
	}
}


void decrypt(char a, char b, vector<char>& inputA, vector<char>& inputB){
	int x1, x2, y1, y2;

	for(int i = 0; i < MAT_SIZE; i++)
		for(int j = 0; j < MAT_SIZE; j++)
			if (mat[i][j] == a){
				x1 = i;
				y1 = j;
				break;
			}

	for(int i = 0; i < MAT_SIZE; i++)
		for(int j = 0; j < MAT_SIZE; j++)
			if (mat[i][j] == b){
				x2 = i;
				y2 = j;
				break;
			}
	if (x1 == x2){
		inputA.push_back(mat[x1][(y1 - 1) % MAT_SIZE]);
		inputB.push_back(mat[x2][(y2 - 1) % MAT_SIZE]);
	}

	else if (y1 == y2){
		inputA.push_back(mat[(x1 - 1) % MAT_SIZE][y1]);
		inputB.push_back(mat[(x2 - 1) % MAT_SIZE][y2]);
	}

	else{
		inputA.push_back(mat[x2][y1]);
		inputB.push_back(mat[x1][y2]);
	}

}


void solve(vector<char> & inputA, vector<char> & inputB){
	vector<char>:: iterator it = inputA.begin();
	vector<char>:: iterator it2 = inputB.begin();
	vector<char> outputA, reoutA;
	vector<char> outputB, reoutB;

	cout << "\n The Digraph Message: ";

	for(;it != inputA.end();it++, it2++){
		cout << *it << *it2 << " ";
		encrypt(*it, *it2, outputA, outputB);
	}

	cout << "\n The Encrypt Message: ";
	for(int i = 0; i < outputA.size(); i ++){
		cout << outputA[i] << outputB[i] << " ";
	}

	cout << "\n The Decrypt Message: ";
	for(int i = 0; i < outputA.size() -1; i ++)
		decrypt(outputA[i], outputB[i], reoutA, reoutB);

	it = reoutA.begin();
	it2 = reoutB.begin();
	for(;it != reoutA.end(); it++, it2++)
		cout << *it << *it2 << " ";
}

void consoleInput(vector<char> & inputA, vector<char> &inputB){
		ifstream inf(inputFile);
		char c, i1, i2;
		while((c = inf.get())!= EOF){

	        if(!isalnum(c))
	        continue;
	        i1 = c;
	        i2 = inf.get();
	        while(!isalnum(i2) && i2 != EOF)
	            i2 = inf.get();

	        if(i1 == i2){
	            inputA.push_back(i1);
	            inputB.push_back('!');
	            inputA.push_back('!');
	            inputB.push_back(i2);
	        }
	        else{
	            inputA.push_back(i1);
	            if (i2 == EOF)
	                inputB.push_back('!');
	            else inputB.push_back(i2);
	        }
	    }
		inf.close();
}


int main(){
	string s1;
	cout << "\n Enter key string for the matrix: ";
	cin >> s1;
	build_matrix(s1, mat);

	vector <char> inputA;
	vector <char> inputB;
	consoleInput(inputA, inputB);

	solve(inputA, inputB);
	cout<< endl << endl;


	return 0;
}
