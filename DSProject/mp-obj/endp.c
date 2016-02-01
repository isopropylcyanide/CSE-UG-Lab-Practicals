#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"sort/sort_main.h"
#include"linked/list.h"
#include"stacks/stacks.h"
#include"queues/queue.h"
#include"trees/tree.h"
#include<ncurses.h>


int main()
{

 initscr();
 curs_set(0);
 raw();
 start_color();
 init_pair(1,COLOR_RED,COLOR_BLACK);
 init_pair(2,COLOR_GREEN,COLOR_BLACK);
 init_pair(3,COLOR_YELLOW,COLOR_BLACK);
 init_pair(4,COLOR_WHITE,COLOR_BLACK);
 init_pair(5,COLOR_CYAN,COLOR_BLACK);
 init_pair(6,COLOR_MAGENTA,COLOR_BLACK);


  int k = 1,z;


  while(k)
   {
     attron(A_BOLD|COLOR_PAIR(1));

    for(i=3; i>=0; i--)
 	 {
 	 printw("\n (Tips: Use 0 for false & 1 for true) ");
   	 printw("\n PLEASE WAIT. LOADING PROJECT \n\n ");
 	 printw("\n\n Loaded %d%% \n",((3-i)*100/3));
 	 refresh();
 		system("sleep 1");
 		clear();
 	  }

    refresh();

    attron(A_UNDERLINE|A_REVERSE|COLOR_PAIR(2));
    printw("\n MICROPROJECT - DATA STRUCTURES (NOV 2014) ");
    printw("\n DEVELOPER - Aman Garg ");
    printw("\n ROLL - 13103050 \n");
    attroff(A_UNDERLINE|A_REVERSE);

    printw("\n\n Following data structures are available \n");

    printw("\n 1: Array Sorts ");
    printw("\n 2: Linked Lists ");
    printw("\n 3: Stacks ");
    printw("\n 4: Queues ");
    printw("\n 5: Trees ");
    printw("\n 6: Binary Search Trees ");
    printw("\n 7: AVL Trees ");
    printw("\n 0: Exit ");
    		attroff(COLOR_PAIR(2));
    		refresh();
		scanw("%d",&k);
    switch(k)
     {
       case 1:  					     //Arrays
       		system("clear ");
       		attron(COLOR_PAIR(3));
		printw("\n Enter number of elements : ");
		refresh();
  		scanw(" %d",&n);
  		printw("\n Enter %d (line separated) elements : \n",n);
  		refresh();

  		for(i=0;i<n ;i++ )
  		scanw("%d",&a[i]);

  		printw("\n Size of array is %d ",n);
		printw("\n The entered list : ");
 		for(i=0; i<n; i++)
 		{printw(" %d ",a[i]);
 		refresh();
 		}

        system("clear ");
 		endwin();
 		options_s(a);
		system("clear ");
		refresh();
   		attron(COLOR_PAIR(3));
   					break;

 	case 2:  {
 		  attron(COLOR_PAIR(4));
 		  system("clear ");					//Linked lists
 	 	  printw("\n 1: Singly Linked ");
    		  printw("\n 2: Doubly Linked ");
    		  printw("\n 0: Back 	\t");
    		  		refresh();
 	 	 		scanw("%d",&k);
 	 	 switch(k)
    		  {
    		  case 0:	system("clear "); main(); break;
 	 	  case 2:	{
 	 	  		system("clear ");
 	 	 		node *head=NULL;
 	 	 		endwin();
  		 		head=createlist();
  		 		system("clear ");
  		 		if(head) options_dl(head);
  		 		system("clear ");
  		 		refresh();
  		 		}	break;

 	 	  case 1:	{
 	 	  		system("clear ");
 	 	 		node *head=NULL;
 	 	 		endwin();
  		 		head=createlists();
  		 		system("clear ");
  		 		if(head) options(head);
  		 		system("clear ");
  		 		refresh();
  		 		}	break;
  		   }
  		 }	attroff(COLOR_PAIR(4)); break;

 								//stacks
 	case 3:
 		{
 		  attron(COLOR_PAIR(5));
 			system("clear ");
 	 	  printw("\n 1: Stacks using arrays ");
    		  printw("\n 2: Stacks using linked lists ");
    		  printw("\n 3: Polish Notations ");
    		  printw("\n 4: Tower of Hanoi ");
    		  printw("\n 0: Back 	\t");
    		  		refresh();
 	 	 		scanw("%d",&k);
 	 	 switch(k)

    		  {
    		  case 0:	system("clear "); main(); break;
    		  case 1:	{
    		  		 system("clear ");
    		  		 stack_a s;
    		  		 s.top=-1;
    		  		 endwin();
 				 options_sa(&s);
 				 system("clear ");
    		  		 refresh();
    		  		}	break;

    		  case 2:	{
    		  		 system("clear ");
    		  		 stack_l *top=NULL;
    		  		 endwin();
    		  		 options_sl(top);
    		  		 system("clear ");
    		  		 refresh();
    		  		}	break;


 	 	  case 3:	{
 	 	  		 system("clear ");
 	 	  		 stack k;
 	 	  		 endwin();
 	 	  		 create_p(&k);
 				 options_p(&k);
 				 system("clear ");
 				 refresh();
  		 		}	break;

 	 	  case 4:	{
 	 	  		 system("clear ");
 	 	  		 char src='A',tmp='C',dest='B' ;
 	 	  		 printw("\n Enter the number of disks ");
 	 	  		 refresh();
  				 scanw("%d",&z);
   				 TOH(z,src,tmp,dest);
   				 system("sleep 2");
   				 system("clear ");
   				 refresh();
 	 	  		}
 	 	  			break;
  		   }
  		 }	break;
 			attroff(COLOR_PAIR(5));
 	 		break;

 	case 4:
 			{
 			attron(COLOR_PAIR(6));
 				system("clear ");					//Queues
 	 	  printw("\n 1: Queues using arrays ");
    		  printw("\n 2: Queues using linked lists ");
    		  printw("\n 0: Back 	\t");
    		  		refresh();
    		  		scanw("%d",&k);
 	 	 switch(k)
    		  {
    		  case 0:	system("clear "); main(); break;
    		  case 1:	{system("clear ");
    		  		 front_a=-1;
    		  		 rear_a=-1;
    		  		 endwin();
    		  		 options_qa(&q);
    		  		 system("clear ");
    		  		 refresh();
    		  		}	break;

    		  case 2:	{system("clear ");
    		  		 count=0;
    		  		 front=NULL;
  				 rear=NULL;
  				 endwin();
   				 options_ql();
   				 system("clear ");
   				 refresh();
    		  		}	break;
  		   }
  		 }	break;
 			attroff(COLOR_PAIR(6));
 			break;

 								//Binary Tree
 	case 5:		{
 			   attron(COLOR_PAIR(1));
 			   system("clear ");
 			   printw("\n BINARY TREE PROGRAM \n");
 			   printw(" Enter (-1) wherever null \n\n");
 			   refresh();
   			   tree * root;
   			   tos=-1; fr=-1; rr=-1;
   			   system("sleep 2");
   			   endwin();
 			   root=createtree();
 			   system("clear ");
		           options_bt(root);
		           system("clear ");
		           refresh();
		           attroff(COLOR_PAIR(1));
 			}

 					break;
 								//Binary Search Tree
 	case 6:		{
 	  		  attron(COLOR_PAIR(3));
 	 		  system("clear ");
 			  printw("\n BINARY SEARCH TREE PROGRAM \n");
  			  printw(" Enter (-1) wherever null \n\n");
  			  refresh();
    			  tree *root=NULL;
    			  tos=-1; fr=-1; rr=-1;
    			  system("sleep 2");
    			  endwin();
     			  options_bst(root);
 			  system("clear ");
 			  refresh();
 			  attroff(COLOR_PAIR(3));
 			}

 					break;			//AVL Tree
 	case 7:		{
 	 		  attron(COLOR_PAIR(4));
 			  system("clear ");
 			  printw("\n AVL TREE PROGRAM \n");
  			  printw(" Enter (-1) wherever null \n\n");
  			  refresh();
  			  tree *root=NULL;
  			  tos=-1; fr=-1; rr=-1;
  			  system("sleep 2");
  			  endwin();
   			  options_av(root);
   			  system("clear ");
   			  refresh();
   			  attroff(COLOR_PAIR(4));
 			}

 					break;
 	case 0:
 		attroff(COLOR_PAIR(1));
 		system("clear ");
 		printw("\n Are you sure to exit : ");
 		refresh();
 		scanw("%d",&z);
 		if(z==1)
 		{

 		for(i=4; i>=0; i--)
 		  {

 		system("clear ");
 		printw("\n Exiting the execution : ");
 		printw("\n Removing core dumps . Please wait. \n");

 		printw("\n\n ACKNOWLEDGEMENTS : ");
 		printw("\n Ashish Sir ");

 		printw("\n\n REFERENCES : ");
 		printw("\n 1: Linux Manual : ");
 		printw("\n 2: Internet ");
 		printw("\n 3: DSA Books\n ");

 		printw("\n THANKS : \n");

 		printw("\n\n Releasing assets %d%% \n",((4-i)*100/4));
 		refresh();

 		system("sleep 1");
 		clear();
 		   }
 		   break;
 		}

 		else	system("clear "); main();


 		break;

 	default:

 		 printw("\n\n Wrong choice specified in the main menu \n");
 		 refresh();
 		 break;

      }

   }
   	attroff(COLOR_PAIR(1));
   	endwin();
   	return 0;
  }
