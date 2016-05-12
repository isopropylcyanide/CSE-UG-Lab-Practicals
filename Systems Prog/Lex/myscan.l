%{
#include "myscan.h"
%}

%%
:				return COLON;
"name"				return NAME;
"roll"				return ROLL;
"group"				return GROUP;
"class"				return CLASS;

[a-zA-Z][_a-zA-Z0-9]*		return IDENTIFIER;
[1-9][0-9]*			return INTEGER;
[ \t\n]				;
.				printf("Unexpected character\n");

%%
int yywrap(){
   return 1;
}













