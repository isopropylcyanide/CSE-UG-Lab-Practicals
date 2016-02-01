#ifndef TREE_H
#define TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define end printf("\n")

typedef struct trees
{
  int data;
  struct trees *left,*right;
  int height;
}tree;	

int tos,fr,rr,flag; 
 
tree* st[20]; 
tree* sq[20];		

int i,j,c,k,l,z; 

tree *createtree();
int  size(tree *);	 void pre(tree *);	void lorder(tree *);
void inor(tree *);	 void push_bt(tree *t);	void inorit(tree *);
int search(tree *,int); void post(tree *);	tree * pop_bt();
void depth(tree *);      void display_bt(tree *);
void options_bt(tree *); void leaves(tree *); 	 	     
tree * delete_bt(tree *);
void enqueue_bt(tree *);
tree *deque_bt();
	
tree *parent(tree *,int);  tree *lca(tree *,int,int);
tree* delbst(tree *);
tree* insbst(tree *,int);
void searchbst(tree *);
void options_bst(tree *);

tree * delavl(tree *);		void balance(tree *);
tree * insavl(tree *,int);	void options_av(tree *);
tree * rotateWithLeft(tree *);  int height(tree *);
tree * rotateWithRight(tree *); int max(int,int);
tree * doubleWithLeft(tree *);  tree *rebal(tree *,tree *);
tree * doubleWithRight(tree *); tree * delavl(tree *);



#endif
