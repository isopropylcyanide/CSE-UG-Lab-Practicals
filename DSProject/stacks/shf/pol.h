#ifndef POL_H
#define POL_H

struct sta_p 
{
  int st[40];
  int top;
};
typedef struct sta_p stack;


void create_p(stack *);    	void evalpre(stack *);		void coinpre(stack *);		
void pushp(stack *,char); 	void options_p(stack *);	char top_p(stack *);
char popp(stack *);		void convert_p(stack *);	void copospre(stack *);		
void coin(stack *);		int pope(stack *);		void pushe(stack *,char);
void evalpo(stack *);		void copos(stack *);		int empty(stack *);	
int  check(char );		int  prec(char);		
int  op(int,int,char);		void coinpos(stack *);		

char aa[40];  int i,j,p1,p2,p0 ; 	char q1,xx;  
char b[40];

 

#endif
