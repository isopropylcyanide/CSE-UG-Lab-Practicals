#include<bits/stdc++.h>
using namespace std;

/* A Simple program to implement a text editor*/

int i, j, ec, fg, ec2;
char fn[20], e,c;
FILE *fp1, *fp2,*fp;

void Create(){
    fp1=fopen("temp.txt", "w");
    printf("\n\tEnter the text and press '.' to save\n\n\t");

    while(1){
        c = getchar();
        fputc(c, fp1);
        if(c == '.'){
            fclose(fp1);
            printf("\n\tEnter then new filename: ");
            scanf("%s", fn);
            fp1 = fopen("temp.txt",  "r");
            fp2 = fopen(fn,  "w");

            while(!feof(fp1)){
                c = getc(fp1);
                putc(c, fp2);
            }
            fclose(fp2);
            break;
        }
    }
}

void Display(){
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("\n\tFile not found!");
        fclose(fp1);
        printf("\n\n\tPress any key to continue...");
    }
    while(!feof(fp1)){
        c = getc(fp1);
        printf("%c", c);
    }
    fclose(fp1);
    printf("\n\n\tPress any key to continue...");
}


void Delete(){
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("\n\tFile not found!");
        printf("\n\n\tPress any key to continue...");
    }
    fclose(fp1);
    if(remove(fn) == 0){
        printf("\n\n\tFile has been deleted successfully!");
        printf("\n\n\tPress any key to continue...");
    }
    else
        printf("\n\tError!\n");
        printf("\n\n\tPress any key to continue...");
}

void Append(){
    printf("\n\tEnter the file name: ");
    scanf("%s", fn);
    fp1 = fopen(fn, "r");
    if(fp1 == NULL){
        printf("\n\tFile not found!");
        fclose(fp1);
    }
    while(!feof(fp1)){
        c=getc(fp1);
        printf("%c", c);
    }
    fclose(fp1);
    printf("\n\tType the text and press 'Ctrl+S' to append.\n");
    fp1 = fopen(fn, "a");
    while(1){
        cin >> c;
        if(c == 19)
            fclose(fp1);
        if(c == 13){
            c='\n';
            printf("\n\t");
            fputc(c, fp1);
        }
        else{
            printf("%c", c);
            fputc(c, fp1);
        }
    }
    fclose(fp1);
}


int main(){
    while(1){
        printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ec);
        switch(ec){
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Append();
                break;
            case 4:
                Delete();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
