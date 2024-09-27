#include <stdlib.h>
#include <stdio.h>

#include "heap.h"  

#define DEBUG 1
//#define DEBUG 0


struct heap_struct make_heap_empty(int cap)
{
    struct heap_struct emptyheap;
    emptyheap.items = calloc(cap,sizeof(int));
    emptyheap.N = 0;
    emptyheap.capacity = cap;
	return emptyheap;
}

struct heap_struct make_heap(int N, int * arr)
{
	int i;
    struct heap_struct heap;
    heap.items = arr;
    heap.N = N;
    heap.capacity = N;
	//initial debug print of array
	if(DEBUG == 1)
	{
		printf("in function make_heap, in DEBUG MODE, printing array BEFORE it gets turned into a heap :\n");
		print_heap(heap);
	}
	for (i=(N/2)-1;i>=0;i--)
	{
		sink_down(i,heap.N,arr);
		//all of the debug printing for step by step sorting of the heap
		if(DEBUG == 1)
		{
			printf("\nin function make_heap, in DEBUG MODE, printing array AFTER sink_down at index %d\n",i);
			print_heap(heap);
		}
		
	}
	//the non-debug print of the constructed heap
	print_heap(heap);
	return heap;
}


void destroy(struct heap_struct * heapP)
{
	free(heapP->items);
	heapP->items= NULL;
	heapP->capacity=0;
	heapP->N = 0;
}


void print_heap(struct heap_struct heapS)
{
	int j;
	printf("\nHeap: size: %d, capacity: %d\nIndexes:",heapS.N,heapS.capacity);
	for(j=0; j<heapS.N ;j++)
	{
		printf("%5d, ",j);
	}
	printf("\nValues: ");
	for(j=0; j<heapS.N ;j++)			
	{
		printf("%5d, ",heapS.items[j]);
	}
	printf("\n");
}


void swim_up(int idx, int * arr)
{
	int temp;
	while ((idx>0)&&(arr[idx]>arr[(idx-1)/2]))
	{
		temp = arr[idx];
		arr[idx]=arr[(idx-1)/2];
		arr[(idx-1)/2]=temp;
		idx = idx/2; // integer division=>rounded down
	}
}


void sink_down(int i, int N, int * arr)
{
	int left, right, index, temp;
	left = (2*i)+1;
	right = (2*i)+2;
	index=i;
	if ((left<(N))&&(arr[left]>arr[index]))
		index = left;
	if (((right<(N)))&&(arr[right]>arr[index]))
		index = right;
	if (index!=i)
	{
		temp = arr[index];
		arr[index]=arr[i];
		arr[i]=temp;
		sink_down(index,N,arr);
	}
}

//insert()
void add(struct heap_struct * heapP, int new_item)
{
	//I know there is some kind of error in this function but I cannot find it
	//this error messes up resize.txt and leaves it unsorted somehow.
	printf("\nAdd: %8d\n", new_item);
    if ((heapP==NULL) || (heapP->N==heapP->capacity))
	{
		printf("\nResizing items array\n");
		heapP->items=realloc(heapP->items,2*sizeof(int)*heapP->capacity);
		heapP->capacity=heapP->capacity*2;
	}
    heapP->items[heapP->N] = new_item;
    heapP->N++;
	if(heapP->items[heapP->N-1]>heapP->items[(heapP->N-1)/2])
	{
		swim_up((heapP->N)-1,heapP->items);
	}
}


//Returns (but does not remove) the element of heapS with the largest key.
int peek(struct heap_struct heapS)
{
	if(heapS.items==NULL)
	{
		printf("\nHeap holds no nodes\n");
		return -1;
	}
	return heapS.items[0];	
}

//remove()
int poll(struct heap_struct * heapP)
{
	int temp;
    if((heapP==NULL) || (heapP->N==0))
	{
		printf("The stack is empty. Exit");
		return -1;
	}
	else
    {
		printf("\nRemoved %8d\n",heapP->items[0]);
		temp = heapP->items[0];
		heapP->items[0]=heapP->items[(heapP->N)-1];
		heapP->items[(heapP->N-1)] = temp;
        heapP->N--;
		if(heapP->items[0]<heapP->items[1]||heapP->items[0]<heapP->items[2])
		{
			sink_down(0,heapP->N,heapP->items);
		}
    }
    return temp;
}