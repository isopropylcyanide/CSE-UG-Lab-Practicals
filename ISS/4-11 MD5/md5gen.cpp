#include <bits/stdc++.h>
using namespace std;

#define INPUT_FILE "input"

/* A program to generate the message digest as governed by the MD5 algorithm */

// Initialise chaining variables
uint a0, b0, c0, d0;
vector<uint> K(64); //handles constants
vector<uint> S(64); //handles shuft values

uint getPaddingLength(uint inputBits){
    // Given the number of inputBits, returns the required padding bits in MD5
    int paddingMust = inputBits < 512 ? 512 : 0;
    return 512 - (inputBits + 64) % 512 + paddingMust;
}

string getPaddedString(uint bitCount){
    // Given the number of inputBits, returns the padded string for that input
    uint numZero = bitCount - 1;
    int paddingMust = bitCount < 512 ? 512 : 0;
    return '1' + string(numZero + paddingMust, '0');
}

uint binaryToChar(string &bin){
    // Given a binary form, return the decimal expansion
    uint num = 0, len = bin.size();
    for (uint i = 0; i < len; i++){
        if (bin[i] == '1')
            num +=  1 << (len - 1 - i);
    }
    return num;
}

string numToBinary(uint num, uint padLength){
    // Given an integer, return a string denoting its binary representation padded appropriately
    string binary;
    while(num){
        binary += (num % 2) ? "1" : "0";
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    uint padZero = padLength - binary.size();
    return string(padZero, '0').append(binary);
}


uint leftRotate (uint x, uint c){
    // To left rotate a number x by c bits
    return (x << c) | (x >> (32 -c));
}

void setupConstants(){
    // Setup K and shift array for all 64 rounds
    a0 = 1732584193;     //0x67452301
    b0 = 4023233417;     //0xefcdab89
    c0 = 2562383102;     //0x98badcfe
    d0 = 271733878;     //0x10325476

    for (uint i = 0; i < 64; i++)
        K[i] = uint(4294967296 * abs(sin(i + 1)));

    S[0] = 7; S[1] = 12; S[2] = 17; S[3] = 22; S[4] = 7; S[5] = 12; S[6] = 17; S[7] = 22;
    S[8] = 7; S[9] = 12; S[10] = 17; S[11] = 22; S[12] = 7; S[13] = 12; S[14] = 17; S[15] = 22;
    S[16] = 5; S[17] = 9; S[18] = 14; S[19] = 20; S[20] = 5; S[21] = 9; S[22] = 14; S[23] = 20;
    S[24] = 5; S[25] = 9; S[26] = 14; S[27] = 20; S[28] = 5; S[29] = 9; S[30] = 14; S[31] = 20;
    S[32] = 4; S[33] = 11; S[34] = 16; S[35] = 23; S[36] = 4; S[37] = 11; S[38] = 16; S[39] = 23;
    S[40] = 4; S[41] = 11; S[42] = 16; S[43] = 23; S[44] = 4; S[45] = 11; S[46] = 16; S[47] = 23;
    S[48] = 6; S[49] = 10; S[50] = 15; S[51] = 21; S[52] = 6; S[53] = 10; S[54] = 15; S[55] = 21;
    S[56] = 6; S[57] = 10; S[58] = 15; S[59] = 21; S[60] = 6; S[61] = 10; S[62] = 15; S[63] = 21;
}


void md5(vector<string> &block){
    /* Given a message broken into 512 bit blocks, perform MD5 algorithm */
    //Process the message in successive 512-bit chunks
    setupConstants();

    for (auto a : block){
        cout << "\n BLOCK  => " << a  << endl;
        // for each 512-bit chunk of message
        //break chunk into sixteen 32-bit words M[j], 0 ≤ j ≤ 15
        vector<uint> M(16);
        string subBlock;
        for (uint i = 0, j = 0; i < a.size(); i++){
            subBlock += a[i];
            if ((i + 1) % 32 == 0){
                M[j] =  binaryToChar(subBlock);
                cout << "\n\t Subblock: " << subBlock << " : " <<  M[j];
                subBlock.clear();
            }
        }
        cout << endl;

        //Initialize hash value for this chunk:
        uint A = a0, B = b0, C = c0, D = d0;
        uint F, G, dTemp;

        //16 iterations per four major rounds = 64 rounds
        for (uint i = 0; i < 64; i++){
            if (i <= 15){
                F = (B & C) | (~B & D);
                G = i;
            }
            else if (i >= 16 && i <= 31){
                F = (D & B) | (~D & C);
                G = (5 * i + 1) % 16;
            }
            else if (i >= 32 && i <= 47){
                F = B ^ C ^ D;
                G = (3 * i + 5) % 16;
            }
            else if (i >= 48 && i <= 63){
                F = C ^ (B | ~D);
                G = (7 * i) % 16;
            }
            dTemp = D;
            D = C;
            C = B;
            B = B + leftRotate(A + F + K[i] + M[G], S[i]);
            A = dTemp;
        }
        //Add this chunk's hash to result so far:
        a0 += A;
        b0 += B;
        c0 += C;
        d0 += D;
    }
    // The final chaining variables are a0, b0, c0, d0 (32 bit). Convert them to hex and append
    cout << "\n Final Chaining variable: \n";
    cout << "\t\tA: " << a0 << ": " <<  hex << a0 << endl;
    cout << "\t\tB: " << b0 << ": " <<  hex << b0 << endl;
    cout << "\t\tC: " << c0 << ": " <<  hex << c0 << endl;
    cout << "\t\tD: " << d0 << ": " <<  hex << d0 << endl;

    stringstream md;
    md << hex << a0 << hex << b0 << hex << c0 << hex << d0;
    cout << "\n MD5 Digest: " << md.str() << endl << endl;
}


int main(){
    // Read input file char by char and process it into 512 bit (64 bytes) inputS
    // 1 char = 1 byte. So array[64] to hold one block
    ifstream inf(INPUT_FILE);
    char c;

    vector< string > block; //64 bytes per block
    static uint byteCount = -1;
    uint bitCount = 0;

    string inputString;

    while( (c = inf.get())!= EOF){
        inputString += c;
        byteCount += 1;
    }

    inputString.erase(remove(inputString.begin(), inputString.end(), '\n'));
    bitCount = byteCount * 8;

    cout << "\n Number of bytes in original message: " << byteCount;
    cout << "\n Number of bits in original message: " << bitCount << endl;

    cout << "\n Length of message to be appended:  64 bits ";
    cout << "\n Number of bits to be padded : " << getPaddingLength(bitCount) << endl;

    string byteTobit;
    for (char c : inputString)
        byteTobit += numToBinary(c, 8);

    inputString = byteTobit;
    cout << "\n ORIGINAL: \n" << inputString << endl;


    string paddedString = getPaddedString(getPaddingLength(bitCount));
    cout << "\n PADDED: \n" << paddedString << endl;
    inputString += paddedString;

    string lengthString = numToBinary(bitCount, 64);
    inputString += lengthString;
    cout << "\n LENGTH(64): \n" << lengthString << endl;
    // Process non padded bytes into block
    string blockString = "";


    for (uint i = 0; i < inputString.size(); i++){
        blockString += inputString[i];

        if ((i + 1)% 512 == 0){
            block.push_back(blockString);
            blockString.clear();
        }
    }

    // 64 byte = 512 bit blocks are ready
    md5(block);


    inf.close();
    return 0;
}
