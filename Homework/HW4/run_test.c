//Jacob Ketterer
//1001793039

#include "heap.c"  
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main()
{
    int i, arraysize, arrayinput, opsize;
    char input[50], opstring[50];
    FILE* inputfile;
    //reading user input for file name
    printf("\nEnter the name of the data file (.txt is included): ");
    scanf("%s",input);
    inputfile = fopen(input,"r");
    if (inputfile == NULL)
    {
        //error messaging
        printf("File could not be opened\n");
        exit(-1);
    }
    fscanf(inputfile,"%d", &arraysize);

    //dynamically allocated array
    int* arr = calloc(arraysize, sizeof(int));

    //reading file input for array
    for(i=0;i<arraysize;i++)
    {
        fscanf(inputfile, "%d", &arrayinput);
        arr[i]= arrayinput;
    }
    
    //creates the heap
    struct heap_struct newheap = make_heap(arraysize, arr);

    //scans the number of operations to perform on the heap from the textfile
    fscanf(inputfile,"%d", &opsize);
    printf("%d",opsize);
    for(i=0;i<opsize;i++)
    {
        //takes the operation as a string from the inputfile
        fscanf(inputfile,"%s", opstring);
        //checks which operation is in the file and executes that operation
        if(!strcmp(opstring,"*"))
        {
            printf("\nOperation number %d, string: %s",i+1,opstring);
            poll(&newheap);
        }
        if(!strcmp(opstring,"p"))
        {
            printf("\nOperation number %d, string: %s",i+1,opstring);
            printf("\nPeek: %8d",peek(newheap));
        }
        if(!strcmp(opstring,"P"))
        {
            printf("\nOperation number %d, string: %s",i+1,opstring);
            printf("\nPeek: %8d",peek(newheap));
                
        }
        if((strcmp(opstring,"*"))&&(strcmp(opstring,"p"))&&(strcmp(opstring,"P")))
        {
            printf("\nOperation number %d, string: %s",i+1,opstring);
            add(&newheap,atoi(opstring));
        }
        print_heap(newheap);
    }
    printf("\n");
    //frees the memory
    destroy(&newheap);
    destroy(&newheap);
    //closes the inputfile so there is no issues with it in the future after the program ends
    fclose(inputfile);
}