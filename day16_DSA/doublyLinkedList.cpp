#include<iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
};


void push(Node** head_ref, int new_data){

    Node* new_node = new Node();

    Node* last = *head_ref;
    new_node->data=new_data;


    new_node->next=NULL;

    if (*head_ref == NULL)
    {
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }

    while (last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    new_node->prev=last;
    return;
} 


void printList(struct Node* node)  
{  
    struct Node* last;  
    printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d ", node->data);  
        last = node;  
        node = node->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d ", last->data);  
        last = last->prev;  
    }  
}  

int main()  
{  
    /* Start with the empty list */
    struct Node* head = NULL;  
    push(&head, 7);  
  
    push(&head, 1);  
  
    push(&head, 4);  
  
    printf("Created DLL is: ");  
    printList(head);  
  
    return 0;  
}  
