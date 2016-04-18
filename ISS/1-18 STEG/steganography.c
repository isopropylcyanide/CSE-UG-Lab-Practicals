// Demonstrate steganography
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

static int byteSize;
#define MAX 1000
#define BITS_CHAR 8
#define input_file "input.txt"
#define crypt_file "updated_input.txt"

// A program to hide the message

void getBinary(char * inp, int * binary){
        for (int i = 0; i < strlen(inp); i++) {
                int ascii = (int) inp [i];
                int counter = BITS_CHAR * (i + 1) - 1;
                while (ascii) {
                        binary[counter] = ascii % 2;
                        ascii /= 2;
                        counter -= 1;
                }
        }
}


void readAndCrypt(int * binary){
    // Creates a crypted file from the given input that contain our message
    // Here, we denote a binary 0 with a single space and 1 with two spaces.
        char myLine[MAX] = {' '};
        FILE * fp = fopen(input_file, "r");
        FILE* fout = fopen(crypt_file, "w");

        int charRead = fread(myLine, sizeof(char), MAX, fp);
        int arrayCounter = 0, i = 0;

        while (i < charRead && arrayCounter < byteSize) {
                if (isspace((int)myLine[i]) && binary[arrayCounter] == 0) {
                        // printf("\nWriting single at %d", i);
                        fwrite(&myLine[i], sizeof(char), 1, fout);
                        arrayCounter += 1;
                }
                else if (isspace((int)myLine[i]) && binary[arrayCounter] == 1) {
                        // printf("\nWriting double at %d", i);
                        fwrite(&myLine[i], sizeof(char), 1, fout);
                        fwrite(&myLine[i], sizeof(char), 1, fout);
                        arrayCounter += 1;
                }

                else fwrite(&myLine[i], sizeof(char), 1, fout);
                i++;
        }

        fclose(fp);
        fclose(fout);
}

void readAndDecrypt(){
    // Decrypts information from the updated input file used as a stegnograph
    // Converts the result back into the value we want
        FILE* fout = fopen(crypt_file, "r");
        assert(fout);

        char myLine[MAX] = {' '};
        int charRead = fread(myLine, sizeof(char), MAX, fout), i = 0;
        int final [MAX] = {0}, finalCounter = 0, ans = 0;

        while (i < charRead  && finalCounter < byteSize) {
                if (isspace((int) myLine[i]) ) {
                        if ((i + 1) < charRead && isspace((int)myLine[i + 1])) {
                                // printf("\nReading double at %d", i);
                                final[finalCounter] = 1;
                                i++;
                        }
                        else {
                                // printf("\nReading single at %d", i);
                                final[finalCounter] = 0;
                        }
                        finalCounter += 1;
                }
                i++;
        }

        char decrypt[MAX] = {' '};
        printf("\n\nReceived the message: \t");

        for (int i = 0; i < byteSize; i++) {
                if (final [i] == 1)
                        ans += pow(2, BITS_CHAR - 1 - (i % BITS_CHAR));

                if (i > 0 && (i + 1) % BITS_CHAR == 0) {
                        char sm [2] = {(char) ans,'\0'};
                        strcat(decrypt, sm);
                        ans = 0;
                }
        }
        printf("%s\n",decrypt);
}


int main(){
        char user_input[MAX];
        // Ask user for a text to encrypt
        printf("\nEnter a string to encrypt\t");
        fgets(user_input, MAX, stdin);
        // fscanf(stdin, "%s[^\n]",user_input );
        byteSize = strlen(user_input)* BITS_CHAR;


        int binary[MAX] = {0};
        getBinary(user_input, binary);

        //read carrier file and crypt it into a new file
        readAndCrypt(binary);
        // read crypt file and print output
        readAndDecrypt();
        return 0;

}
