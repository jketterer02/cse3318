#include <stdlib.h>
typedef struct node* nodePT;
struct node
{
    int data;
    struct node* next;
};
void swap_2_after(nodePT prev){
    if ( (prev->next == NULL) || (prev->next->next == NULL) )
    {
        return;
    }
		nodePT A = prev->next;
        nodePT B = A->next;
        nodePT C = B->next;
        prev->next = B; //8
		B->next = A;    //9
		A->next = C;    //10
}
int main(int argc, char* argv[])
{
    
}
