#include "hw1_student.h"  // .h extenssion, not .c

// You do not need to change this print_1D function. It is included here for 
// your convenience, in case you need to call it while debugging.
void print_1D(int sz, int * arr){
	for(int k = 0; k< sz; k++){
		printf("%8d", arr[k]);
	}
	printf("\n");
}


/* dynamically allocates an array and populates it with all values from arr 
	that are strictly smaller than thresh. 
	Returns:
		- the pointer to the dynamically allocated array.
		- NULL if all elements of arr are greater or equal to thres. In this case it does not allocate any memory, and sets content of sz_res to 0.
*/
int* get_scores_below(int thresh, int sz_arr, int* arr, int* sz_res)
{
	// change code here to correct function implementation
    int count = 0;
    int i;
    int x = 0;
    for(int i=0;i<sz_arr;i++)
    {
        if (arr[i] < thresh)
            count++;
    }
    *sz_res = count;
    int* array = malloc(count*sizeof(int));
	for(i=0;i<sz_arr;i++)
    {
        if(arr[i]<thresh)
        {
            array[x] = arr[i];
            x++;
        }
    }
    return array;
}

void update_min_max(int num_rows, int num_cols, int* arr2D[], int* arr_min, int* arr_max)
{
    int r,c;
	int tempmax = -999999999;
    int tempmin = 999999999;
    for(r = 0; r<num_rows; r++)
    {
		for(c=0; c<num_cols; c++)
        {
			if((arr2D[r][c]>tempmax))
            {
                tempmax = arr2D[r][c];
            }
            if(arr2D[r][c]<tempmin)
            {
                if(arr2D[r][c] != 0)
                    tempmin = arr2D[r][c];
            }
		}
	}
    *arr_max = tempmax;
    *arr_min = tempmin;

}


// improve this code to print as required in the homework
void print_2D(int num_rows, int num_cols, int* arr2D[]){	
	int r,c,c2;
	printf("\n |");
    for(c2 = 0; c2<num_cols; c2++)
    {
        printf("%8d|", c2);
    }
    printf("\n");
    for(c2 = 0; c2<(10*num_cols); c2++)
    {
        printf("-");
    }
    printf("\n");
	for (r = 0; r<num_rows; r++)
    {
        printf("%d|", r);
		for(c=0; c<num_cols; c++)
        {
			printf("%8d|", arr2D[r][c]);
		}
		printf("\n");
	}	
}
