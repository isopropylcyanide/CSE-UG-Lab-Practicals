#include<iostream>
#include<cstdlib>
using namespace std;

class heapsort
{
    int num;
    int *array;
    heapsort *maxHeap;

public:
      heapsort(){}
      heapsort(int argc,char **argv)
      {
        num=argc-1;
        array=new int[num];
        for(int i=1; i<argc; i++)
          array[i-1]=atoi(argv[i]);
      }

      void print()
      {
        for(int i=0; i<num; i++)
          cout<<"  "<<array[i];
        cout<<endl;
      }
      void swap(int* a, int* b) { int t = *a; *a = *b;  *b = t; }


      void maxHeapify(heapsort*maxHeap ,int i)
      {
        int largest=i;
        int left=(i<<1)+1;
        int right=(i+1)<<1;

        if (left < maxHeap->num && 
        maxHeap->array[left] > maxHeap->array[largest])
        largest = left;
  
        if (right < maxHeap->num && 
        maxHeap->array[right] > maxHeap->array[largest])
        largest = right;
 
        if (largest != i)
         {
         swap(&maxHeap->array[largest], &maxHeap->array[i]);
         maxHeapify(maxHeap, largest);
        }
      }

      heapsort* createHeap()
      {
        maxHeap->num=this->num;
        maxHeap->array=this->array;

        for(int i=num; i>0; i--)
          maxHeapify(maxHeap,i);
        return maxHeap;
      }

      void heap_sort()
      {
       maxHeap=createHeap();
       while(maxHeap->num>1)
        {
          swap(&maxHeap->array[0], &maxHeap->array[maxHeap->num - 1]);
          maxHeap->num-=1;
        }
        maxHeapify(maxHeap,0);
      }
};

int main(int argc,char **argv)
{
	if (argc<2){cout<<"\n Too few Arguments\n"; return 0;}

  heapsort *h=new heapsort(argc,argv);
  cout<<"\n Before Sort : ";
  h->print();

  cout<<"\n After Sort : ";
  h->heap_sort();

  return 0;
}