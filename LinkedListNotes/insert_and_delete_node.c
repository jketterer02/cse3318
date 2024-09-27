#include <stdlib.h>
#include <stdio.h>
typedef struct node* nodePT;
struct node
{
    int data;
    struct node* next;
};
void insert_node_after(nodePT prev, nodePT newP)
{
    if((prev==NULL)||(newP==NULL))
    {
        printf("prev or newP pointer (or both) are null");
    }
    else
    {
        newP->next = prev->next; //newP now points to the adress previous was orignally pointing to
        prev->next = newP; // prev points to newP
    }
}
nodePT insert_node_start(nodePT L, nodePT prev, nodePT newP)
{
    if(prev==NULL) //if there is no pointer prev at the start of the list
    {
        newP->next = L; // newP points to start
        return newP; //returns pointer to newP
    }
    else
    {
        insert_node_after(prev, newP);
        return L;
    }
}
void delete_node_after(nodePT prev)
{
    if(prev == NULL)
        return;
    else
    {
        nodePT toDelete = prev->next; //toDelete stores the memory adress of prev->next
        if(toDelete != NULL)
        {
            prev->next = toDelete->next;//previous bypasses and points to the address after the about to be deleted node
            free(toDelete);
        }
    }
}
nodePT delete_node(nodePT L, nodePT prev)
{
    if(prev == NULL) //if L is the beginning of the list delete first node
    {
        if(L == NULL){return NULL;}
        else
        {
            nodePT newFirst = L->next;
            free(L);
            return newFirst;
        }
    }
    else
    {
        delete_node_after(prev);
        return L;
    }
}

int main(int argc, char* argv[])
{

}