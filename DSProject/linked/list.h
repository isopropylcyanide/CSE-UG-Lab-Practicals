#ifndef LIST_H
#define LIST_H

#include<stdio.h>
#include<malloc.h>
#include<string.h>                                  
#include<stdlib.h>
#define endl printf("\n");


struct link                                          //basic structure
{
 int rno; 
 char name[10]; 
 int marks;
 struct link* next,*prev;
};

typedef struct link node; 
extern node *head;

node *head2;

int z,c,i,d;

node *createlists();
node *createlist();
void display_l(node *); node * del(node *);         	    		
node * del_end(node *);   node * iith_end(node *);    void rmdup(node *);
node * insert(node *);    node * del_ith(node *);     node * del_beg(node *);  	
node * ins_beg(node *);   node * dith_beg(node *);    void concat(node *);		
node * ins_end(node *);   node * dith_end(node *);    void sort(node *);
node * ins_ith(node *);   void options(node *);     void instj(node *); 
node * iith_beg(node *);  node * rev(node *);	   
	 


    	
node * ins_begd(node *);   node * dith_begd(node *);  node * deld(node *);	
node * ins_endd(node *);   node * dith_endd(node *);  node * insertd(node*);  
node * del_endd(node *);   node * iith_endd(node *);  node * del_ithd(node *);
node * iith_begd(node *);  void display_dl(node *); node * ins_ithd(node *);	  
node* revd(node *);  	 node * del_begd(node *);   
void options_dl(node*);

 
#endif

