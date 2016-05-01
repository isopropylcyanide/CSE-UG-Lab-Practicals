#include <iostream>
#include <bits/stdc++.h>
#define inputFile "input.txt"
using namespace std;

vector <char> inputA, inputB;
vector <char> outA, outB;
vector< vector<char> > M;

void displayMatrix(){
    for (auto a: M){
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }
}

void createMatrix(set<char> &uniq){
    M.resize(5);
    int i = 0, row = 0;
    char c;

    for (auto a : uniq){
        if (i < 5)
            M[row].push_back(a);
        if (i + 1 == 5){
            row += 1;
            i = 0;
        }
        i++;
    }

    // i is the index and row denotes the current row
    int j = 97;
    while (j < 123){
        c = char(j);
        // treat i and j as same
        if (uniq.find(c) == uniq.end()){
            M[row].push_back(c);
            i++;
            if (i == 5){
                row += 1;
                i = 0;
            }
            if (c == 'i')
                j ++;
        }
        else {
            if (c == 'i')
                j ++;
        }
        j += 1;
    }
    displayMatrix();
}

void displayDigraph(){
    for (auto a : inputA)
        cout << a <<" ";
    cout << endl;
    for (auto a : inputB)
        cout << a <<" ";
    cout << endl;
}

void encrypt(){
    char a, b;
    int x1, x2, y1, y2;
    outA.clear();
    outB.clear();

    for (int i = 0; i < inputA.size(); i++){

        a = inputA[i];
        b = inputB[i];
        printf("a: %c, b: %c \t",a, b );

    	for(int i = 0; i < 5; i++)
    		for(int j = 0; j < 5; j++)
    			if (M[i][j] == a){
    				x1 = i;
    				y1 = j;
    				break;
    			}

    	for(int i = 0; i < 5; i++)
    		for(int j = 0; j < 5; j++)
    			if (M[i][j] == b){
    				x2 = i;
    				y2 = j;
    				break;
    			}

        // same row
    	if (x1 == x2){
            printf("Same row\n");
    		outA.push_back(M[x1][(y1+1)%5]);
    		outB.push_back(M[x2][(y2+1)%5]);
    	}
        // same column
    	else if (y1==y2){
            printf("Same col\n");
    		outA.push_back(M[(x1+1) % 5][y1]);
    		outB.push_back(M[(x2+1) % 5][y2]);
    	}
        // end points of the rectangle so formed
    	else{
            printf("Rectangle\n");
    		outA.push_back(M[x2][y1]);
    		outB.push_back(M[x1][y2]);
    	}
    }
    printf("\nThe encrypted string: \n");
    for (auto a : outA)
        cout << a <<" ";
    cout << endl;
    for (auto a : outB)
        cout << a <<" ";
    cout << endl;
}

void decrypt(){
    char a, b;
    int x1, x2, y1, y2;
    for (int i = 0; i < outA.size(); i++){
        a = outA[i];
        b = outB[i];

    	for(int i = 0; i < 5; i++)
    		for(int j = 0; j < 5; j++)
    			if (M[i][j] == a){
    				x1 = i;
    				y1 = j;
    				break;
    			}

    	for(int i = 0; i < 5; i++)
    		for(int j = 0; j < 5; j++)
    			if (M[i][j] == b){
    				x2 = i;
    				y2 = j;
    				break;
    			}

        // same row
    	if (x1 == x2){
    		printf("%c",M[x1][(y1-1)%5]);
    		printf("%c",M[x2][(y2-1)%5]);
    	}
        // same column
    	else if (y1==y2){
    		printf("%c",M[(x1-1) % 5][y1]);
    		printf("%c",M[(x2-1) % 5][y2]);
    	}
        // end points of the rectangle so formed
    	else{
    		printf("%c",M[x2][y1]);
    		printf("%c",M[x1][y2]);
    	}
        printf(" ");
    }
    printf("\n");
}

int main(){
    string s;
    // input key
    printf("Enter a string as key: \t");
    cin >> s;

    //set up matrix
    printf("\nThe matrix: \n");
    set<char> uniq;
    for (auto a : s)
        uniq.insert(a);
    createMatrix(uniq);

    // read input and form digraph
    ifstream inf(inputFile);
    char c, i1, i2;

    while((c=inf.get())!=EOF){

        if(!isalnum(c))
        continue;
        i1 = c;
        i2 = inf.get();
        while(!isalnum(i2) && i2 !=EOF)
            i2 = inf.get();

        i1 = tolower(i1);
        i2 = tolower(i2);
        i1 = (i1 == 'j')?'i':i1;
        i2 = (i2 == 'j')?'i':i2;

        if(i1 == i2){
            inputA.push_back(i1);
            inputB.push_back('x');
            inf.unget();
        }
        else{
            inputA.push_back(i1);
            if (i2 == EOF)
                inputB.push_back('x');
            else inputB.push_back(i2);

        }
    }
    inf.close();

    printf("\nThe digraph: \n");
    displayDigraph();

    printf("\nEncryption process: \n");
    encrypt();

    printf("\nThe decrypted string: \n");
    decrypt();

    return 0;
}















//
