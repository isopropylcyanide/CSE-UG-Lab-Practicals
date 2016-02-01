#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX 1000

static int num_nodes = 6;
static int router_valid[MAX];
static int s;

char * file;
char * temp;

typedef struct link{
	int data;
	struct link *next;
 }queue;

typedef struct router{
	int * dest;
	int * dist;
	int * next;
 }router;

router * own;

typedef struct thread_info{
	pthread_t thread_id;
	int thread_no;
	void *argument;
 }thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void pretty_error(char * message){
    fprintf(stderr, " Error: %s\n ", message );
 }


void display_own(int node){
	//Displays the routing table of n'th node

    printf("\n\nDistance Vector Table for %d : \n",node+1 );
    if(router_valid[node] == 0){
        printf(" ROUTER CURRENTLY INVALIDATED\n");
        return;
    }
    
    printf("DEST \t VALID \tDIST \t NEXT");
    for(int i = 0; i < num_nodes; i++){

		if (own[node].next[i]!=0)
			printf("\n%d \t %d \t %d \t %d",own[node].dest[i],router_valid[i],own[node].dist[i],own[node].next[i] );
		else
			printf("\n%d \t %d \t %d \t -",own[node].dest[i],router_valid[i],own[node].dist[i]);
	}
	printf("\n");
 }


void get_init_table(FILE*fp,int file_no){
	//Initialise values to the table from the input file

	char input[10];
	int i=0;
	while (fgets(input,10,fp)){
		int a,b,c;
		sscanf(input,"%d%d%d",&a,&b,&c);
		own[file_no].dest[i]=a;
		own[file_no].dist[i]=b;
		own[file_no].next[i]=c;
		i+=1;
 	}
 }


void enqueue(queue **front,queue** rear,int data){
	//Enqueues the required node for processing by each thread

	queue *temp;
	temp=(queue *)malloc(sizeof(queue));
	temp->next=NULL;
	temp->data=data;

   	if(*rear==NULL)
   		*front=*rear=temp;
   	else {
   		queue *p=*front;
   		if((*rear)->data==data)return;
   		while(p!=*rear){
   			if (p->data==data)return;
   			p=p->next;
   		}
   		(*rear)->next=temp;
   		(*rear)=temp;
   	}
 }


int dequeue(queue **front,queue** rear){
	//Dequeues the node for a thread

    queue * p=*front;
    int data=0;

    if(p==NULL)return -1;
    if(p->next!=NULL) {
       data=p->data;
       p=p->next;
       free(*front);
       *front=p;
     }
     else {
        data=p->data;
        free(*front);
        *front=*rear=NULL ;
      }
    return data;
  }


void exchange_values(int file_no){
	//This is where each thread will interact with the remaining
	//nodes and update its table if necessary

    //if it's an invalid router, notify all it's direct links and those nodes
    //that have it as a next hop, that they are no longer reachable from itself.
    //Return peacefully. Obtain locks during the entire process
    
	pthread_mutex_lock(&mutex);
    
    if (router_valid[file_no] == 0){

        for(int node=0; node<num_nodes; node++){

            if (node == file_no)
                continue;

            if (own[file_no].dist[node] == 1){
                //Preserve your own link but fail the link from their side
                own[node].dist[file_no] = 16;
                own[node].next[file_no] = 0;
            }
            //For each subnode from this router, if these two have a next_hop
            //at the faulty router, then invalidate the route
            for (int subnode = 0; subnode<num_nodes; subnode++){

                if (node == subnode || subnode == file_no)
                    continue;

                else if (own[node].next[subnode]  == file_no + 1){
                    printf("\n Subnode %d delinked from %d ",subnode+1,node+1);
                    own[node].next[subnode] = 0;
                    own[node].dist[subnode] = 16;
                }
            }
        }
    }


    //else this is a valid router
    else{    

    	queue *front = NULL,*rear=NULL;

    	for(int node=0; node<num_nodes; node++){

            if (node == file_no)
                continue;

            //if the connected router under consideration is faulty
            //set its distance as unreachable from the host

            if (own[file_no].dist[node] == 1 && router_valid[node] == 0){
                own[file_no].dist[node] = 16;
                own[file_no].next[node] = 0;
                continue;
            }


            //if its a valid router, then it may have been a direct link to 
            //the given router before, check for that case!
            //if it was direct before, it needs to be direct now

            if (router_valid[node] && own[node].dist[file_no] == 1){
                own[file_no].dist[node] = 1;
                own[file_no].next[node] = 0;
            }

            //else if it's a normal direct link
            // enqueue it to receive updates

    		if (own[file_no].dist[node] == 1 && router_valid[node])
    			enqueue(&front,&rear,node);

    	}

    	int node = 0;
    	while((node = dequeue(&front,&rear))!=-1)
    		for(int k=0; k<num_nodes; k++){
    			 
                //can't utilise an invalid router as next hop
                if (router_valid[k] == 0 ){
                    own[file_no].dist[k] = 16;
                    own[file_no].next[k] = 0;
                }


    			if ((own[node].dist[k] + 1 < own[file_no].dist[k]) && router_valid[k]){
    				own[file_no].next[k] = node + 1;
    				own[file_no].dist[k] = own[node].dist[k] + 1;
    			}
            }
        }

	pthread_mutex_unlock(&mutex);	
 }


void * thread_work(void *arg){
	//Each of the created thread has to do this work 

	char * my_file = (char*)arg;
	int file_no = my_file[0]-'0'-1;

	//Critical Section Starts

	long time_th=10000;
	while(time_th--)
		exchange_values(file_no);
	
	//Critical Section Ends

	// printf("Thread  over with file: %d \n",file_no+1);
	pthread_exit(NULL);
 }


char* get_file_id(int file_id){
	//Returns the file name for a particular thread

	if 		(file_id==0) return "1.txt";
	else if (file_id==1) return "2.txt";
	else if (file_id==2) return "3.txt";
	else if (file_id==3) return "4.txt";
	else if (file_id==4) return "5.txt";
	else if (file_id==5) return "6.txt";
	char arg= file_id +1 + '0';
	temp = (char *)calloc(5,sizeof(char));
	temp[0]=arg;
	temp[1]='.',temp[2]='t',temp[3]='x',temp[4]='t';
	return temp;
  }


void store_initial_files_in_table(){
	/*This function stores the initial file data into tables indexed by their id*/

	char * my_file=NULL; int file_no=0;

	for(int i=0; i<num_nodes; i++){
	  my_file = get_file_id(i);
	  file_no=my_file[0]-'0'-1;
	  // printf("Ich will: %d of %s\n",file_no,my_file );
	  FILE *fp=fopen(my_file,"r");
	  assert (fp!=NULL);
	  get_init_table(fp,file_no);
	  fclose(fp);
	}
 }


void start_threads(int verbose){
	//This function starts the threads each time a change occurs 
	//This will automatically call the update routine

	pthread_attr_t attr;
	s = pthread_attr_init(&attr);
	assert (s == 0);

	thread *tid=(thread *)calloc(num_nodes,sizeof(thread));
	assert (tid!=NULL);

	for(int i=0; i<num_nodes; i++){
		tid[i].thread_no=i+1;
		tid[i].argument=get_file_id(i);
		pthread_create(&tid[i].thread_id,&attr,thread_work,tid[i].argument);
	}

	pthread_attr_destroy(&attr);
	
	for(int i=0; i<num_nodes; i++)
		pthread_join(tid[i].thread_id,NULL);

	//The main thread will continuously display the output on the current screen
    if (verbose)
	   for(int i=0; i<num_nodes; i++)
	       display_own(i);
 }


void initialise_router(int i){
	//Initialises new router in accordance 

	own[i].dest=(int*)malloc(sizeof(int)*MAX);
	own[i].dist=(int*)malloc(sizeof(int)*MAX);
	own[i].next=(int*)malloc(sizeof(int)*MAX);

	for(int existing=0; existing<num_nodes-1; existing++ ){
		own[existing].dest[i]=num_nodes;
		own[existing].dist[i]=16;
		own[existing].next[i]=0;
	}

	for(int existing=0; existing<num_nodes-1; existing++ ){
		own[i].dest[existing]=existing+1;
		own[i].dist[existing]=16;
		own[i].next[existing]=0;
	}
	own[i].dest[i]=i+1;
	own[i].dist[i]=0;
	own[i].next[i]=0;
 }


void add_router(){
	//Adds a new router to the network

	num_nodes+=1;
	printf("Router: %d configuration\n",num_nodes);

	initialise_router(num_nodes-1);

	// int direct[num_nodes];
	printf("Enter direct links (1-%d): (0 to exit) \n",num_nodes-1);

	while((scanf("%d",&s))){
		if (s==0)break;
		own[num_nodes-1].dist[s-1]=1;
		own[s-1].dist[num_nodes-1]=1;
	}
	
	start_threads(1);
 }


void fail_link(int pre_src, int pre_dest, int interactive){
    //Removes a working link from the network

    int src,dest;

    if (interactive){
        printf("Enter source: \t"); scanf("%d",&src);
        printf("Enter destination:  "); scanf("%d",&dest);
        src -=  1;
        dest -= 1;

        printf("f:: %d\n",num_nodes);

        if (src > num_nodes){
            pretty_error(" Source router doesn't exist\n");
            return;
        }

        if (dest > num_nodes){
            pretty_error(" Destination router doesn't exist\n");
            return;
        }
    }

    else {
        src = pre_src;
        dest = pre_dest;
    }

    //Set infinity from source to the dest 
    //or if the next hop to reach it is the dest
    for(int node=0; node<num_nodes; node++ ){
        if (node==src) continue;

        if (own[src].next[node] == dest+1 ||  node==dest){
            own[src].dist[node]=16;
            own[src].next[node]=0;
            own[node].dist[src]=16;
            own[node].next[src]=0;
        }
    }

    //Set infinity from dest to the source
    //or if the next hop to reach it is the source
    for(int node=0; node<num_nodes; node++ ){
        if (node==dest) continue;

        if (own[dest].next[node] == src +1 ||  node == src){
            own[dest].dist[node]=16;
            own[dest].next[node]=0;
            own[node].dist[dest]=16;
            own[node].next[dest]=0;
        }
    }

    start_threads(1);
 }


void revalidate_router(){

    static int invalid = 0;
    static int revalid = 0;

    printf("\n The current invalidated routers are : ");
    for( int i = 0; i< MAX; i++)
        if (router_valid[i] == 0){
            invalid ++;
            printf(" %d , \n", i+1 );
        }

    if (!invalid){
        pretty_error(" No current invalid routers exist in the network\n");
        return;
    }

    else {
        printf("\n Enter the router to be revalidated: "); scanf("%d",&revalid);
        revalid -= 1;
        if (router_valid[revalid] != 0 || revalid > num_nodes){
            pretty_error(" Enter an invalidated router only\n");
            return;
        }
        else {
            router_valid[revalid] = 1;
            start_threads(1);
        }

    }

 }


void invalidate_router(){
    //Fail all links of a given router, if exists;

    printf("\nEnter the faulty router: \t");
    scanf("%d",&s);
    s -= 1;
        
    if(s >  num_nodes){
        pretty_error(" Router doesn't exist\n");
        return;
    }
    
    if (router_valid[s] != 1){
        pretty_error(" Router already deactivated\n");
        return;
    }

    //Fail all connected links from the current router
    //Send a fail prune packet to all of them

    router_valid [s] = 0;
    start_threads(1);
 }


void add_link(){
	//Adds a new link in the network

	int src,dest;
	printf("Enter source: \t"); scanf("%d",&src);
	printf("Enter destination:  "); scanf("%d",&dest);
	src-=1;
	dest-=1;

    if (src >= num_nodes){
        pretty_error(" Source router doesn't exist\n");
        return;
    }

    if (dest >= num_nodes){
        pretty_error(" Destination router doesn't exist\n");
        return;
    }

	own[src].dist[dest]=1;
	own[src].next[dest]=0;
	own[dest].dist[src]=1;
	own[dest].next[src]=0;
	
	start_threads(1);	
 }


void user_input(){

	//User thread that always runs and presents the menu
	int choice = 1;

	while (choice){
		printf("\n*****MENU*******\n\n");
		printf("1: Add a router: \n\n");
		printf("2: Fail a link:\n\n");
		printf("3: Add a link:\n\n");
        printf("4: Invalidate a router\n\n");
        printf("5: Revalidate a router\n\n");
		printf("0: Exit simulation: \t");
		scanf("%d",&choice);
		printf("\n\n\n");

		switch (choice){

			case 1:	add_router();	        break;
			case 2: fail_link(0,0,1);	    break;
			case 3: add_link();		        break;
            case 4: invalidate_router();    break;
            case 5: revalidate_router();    break;
			case 0:	break;
		}
	}
 }


int main(){
	/*
		1)Make each node get their table from a file
		2)Interact with other nodes's tables using threads
		3)Thread arguments contain their respective files
		3)Update your own table
	*/

	own = (router*)calloc(MAX,sizeof(router));
	for (int i = 0; i < num_nodes; i++){
		own[i].dest = (int*)malloc(sizeof(int)*MAX);
		own[i].dist = (int*)malloc(sizeof(int)*MAX);
		own[i].next = (int*)malloc(sizeof(int)*MAX);
	}

    //Initialise routing validity
    for (int i = 0; i < MAX; i++)
        router_valid[i] = 1;

	store_initial_files_in_table();
	start_threads(1);
	user_input();

	/* 
		Once the initial table has been setup, one thread will continuously 
		display the final table on the main terminal for each node.
		The other thread , in a new terminal should wait for user input to:
		a) Add a new node
		b) invalidate a node
		c) Fail a link
		d) Restore a link

		For, each successful operation,
	*/

	return 0;
 }

