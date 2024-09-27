#include <stdlib.h>
typedef struct node* nodePT;
struct node
{
    int data;
    struct node* next;
};
nodePT array_2_list(int arr[], int N)
 {
     int j;
     nodePT lastP = NULL, newP = NULL;
     nodePT L = (nodePT)malloc(sizeof(struct node));
     L->data = arr[0];
    L->next = NULL;
     lastP = L;
    for(j=1;j<N;j++)
     {
         //create a new node
         newP = (nodePT)malloc(sizeof(struct node));
         //write arr[j] as data
         newP->data = arr[j];
         newP->next = NULL;
         lastP->next = newP;
         lastP = newP;

     }
     return L;
}
void destroy_list(nodePT L)
{
    nodePT next, current;
    current = L;
    L = NULL; // can be skipped here
    while(current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
int main(int argc, char* argv[])
{
    
}


