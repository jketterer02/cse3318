// Jacob Ketterer, 1001793039
//Program is meant to sort an unsorted array stored in a .txt file that the user can specify.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "list.h"

//insert into sorted list
nodePT insert_sorted(nodePT L, nodePT newP)
{
        if((L->data==0)&&(L->next==NULL))
        {  
            L->data=newP->data;
        }
        if((L->data!=0)&&(L->data<newP->data))
        {
            insert_node_after(L, new_node(newP->data));
        }
        if((L->data!=0)&&(L->data>newP->data)&&(L->next==NULL))
        {
            insert_front(&L,newP->data);
        }
}

//modified print_list_horz due to my implementation not working with the default
void print_list_horizontal(struct node * my_list) {
    int i = 0;
    struct node * curr;

    printf("\n List items: ");
    for (i = 0, curr = my_list; (curr != NULL); curr = curr->next) {
        if(0!=curr->data)
        {
            //will only print the list of items if the default 0 value isn't present
            printf("%5d    ", curr->data);
            i++;
        }
        else
        {
            //default value of 1 zero will print as NULL
            printf("\n<print_list_horiz> : List is NULL");
        }
    }
	printf("\n Length of above list = %d\n", i);
}

//prints the sorted array 
void print_sorted_array(struct node * my_list) {
    if (my_list == NULL)
        return;
    int i = 0;
    struct node * curr;
    for (i = 0, curr = my_list; (curr != NULL); curr = curr->next) {
        if(0!=curr->data)
        {
            //does not print 0, as 0 is a default value for each index
            printf("%5d,    ", curr->data);
        }
        i++;
    }
}

//prints the initial, unsorted array
void print_array(int arr[], int N){
	int j;
	printf("\nArray: ");
	for(j= 0; j<N; j++){
		printf("%5d,", arr[j]);
	}
	printf("\n");
}

//bucket sort
void bucket_Sort(int array[], int N)
{
    int k;
    int max = -999999999;
    int min = 999999999;
    //min and max intialization is make-shift but should work for everything not near the integer size limit
    nodePT B[N];
    for(k=0;k<N;k++)
    {
        B[k] = calloc(8,sizeof(nodePT));
    }
    for(k=0;k<N;k++)
        if(array[k]>max)
            max = array[k];
    for(k=0;k<N;k++)
        if(array[k]<min)
            min = array[k];
    printf("\nBucketsort: MIN = %d, MAX = %d, N = %d buckets",min,max,N);
    for(k=0;k<N;k++)
    {
        printf("\n");
        int idx = floor((N*(array[k]-(double)min))/(1+(double)max-(double)min));
        printf("Arr[%d]= %5d, ",k,array[k]);
        printf("idx = %d",idx);
        //various checks for inserting first node, before, after, and overwriting default value.
        if(k==0)
        {
            B[idx]->data=array[k];
        }
        if((B[idx]->data==0)&&(B[idx]->next==NULL))
        {  
            B[idx]->data=array[k];
        }
        if((B[idx]->data!=0)&&((B[idx]->data)<array[k]))
        {
            insert_node_after(B[idx], new_node(array[k]));
        }
        if((B[idx]->data!=0)&&((B[idx]->data)>array[k])&&(B[idx]->next==NULL))
        {
            insert_front(&B[idx],array[k]);
        }
    }
    printf("\n");
    for(k=0;k<N;k++)
    {
        printf("---- List at index %d :",k);
        print_list_horizontal(B[k]);
    }
    printf("\nSorted Array:");
    for(k=0;k<N;k++)
        print_sorted_array(B[k]);
    //frees memory
    for(k=0;k<N;k++)
        destroy_list(B[k]);
}

void run1()
{
    int i;
    int arraysize, unsortedint;
    char input[50];
    FILE* inputfile;
    //reading user input for file name
    printf("\nEnter the name of the unsorted array text file (.txt is included): ");
    scanf("%s",input);
    inputfile = fopen(input,"r");
    if (inputfile == NULL)
    {
        //error messaging
        printf("File could not be opened\n");
        exit(-1);
    }
    fscanf(inputfile,"%d", &arraysize);
    int array[arraysize];
    //reading file
    for(i=0;i<arraysize;i++)
    {
        fscanf(inputfile, "%d", &unsortedint);
        array[i]= unsortedint;
    }
    fclose(inputfile);
    //prints unsorted array
    print_array(array,arraysize);
    //sorts the array using buckets, and prints the sorted array, then frees the sorted array
    bucket_Sort(array,arraysize);
}

int main()
{
	printf("This program will read a file name, load data for an array from there and print the sorted array.\n");
	printf("The array is sorted using bucket sort.\n");
	printf("This will be repeated as long as the user wants.\n");
	int option;
	do {
		run1();
		printf("\nDo you want to repeat? Enter 1 to repeat, or 0 to stop) ");
		char ch;
		scanf("%d%c",&option, &ch);  // ch is used to remove the Enter from the input buffer
 	} while (option == 1);

   return 0;
}