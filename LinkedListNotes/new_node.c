#include <stdlib.h>
typedef struct node* nodePT;
struct node
{
    int data;
    struct node* next;
};
nodePT new_node(int value)
{
    nodePT result = (nodePT) malloc(sizeof(struct node));
    result->data = value;
    result->next = NULL;
    return result;
}
int main(int argc, char* argv[])
{
    
}