#include <stdio.h>
#include <stdlib.h>
#include "myscan.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL, "name", "class", "roll", "group"};

int main(){
	int ntok, vtok;
	ntok = yylex();
	while (ntok){
		printf("%d\n", ntok);
		if (yylex() != COLON)
			printf("Syntax error in line: %d, expected  : but found %s\n", yylineno, yytext);
		ntok = yylex();
	}
	return 0;
}
