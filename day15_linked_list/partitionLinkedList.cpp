#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    string name;
    Node *head;
};
struct Node *head;

void InsertatHead(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head != NULL)
    {
        temp->next = *head;
    }
    *head = temp;
}

void InsertAtEnd(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    Node *last = *head;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    return;
}

void Print(Node *head)
{
    // Node* temp=head;
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

Node partitionLinkedList(Node *head,int x)
{

    Node* before_head = new Node();
    Node* before = before_head;
    Node* after_head = new Node();
    Node* after = after_head;
    while (head!=NULL)
    {
        if (head->data<x)
        {
            before->next=head;
            before=before->next;
            
        } else
        {
            after->next=head;
            after=after->next;
        }
        head=head->next;
        
        
    }

    after->next=NULL;
    before->next=after_head->next;
    return *before_head->next;
    

}

int main()
{
    head = NULL; //since this is already pointer to Node
    for (int i = 0; i < 5; i++)
    {
        InsertAtEnd(&head, i); //we will pass the value by reference
    }                          //this will change the value of head;
    Print(head);
        InsertAtEnd(&head, 11);
        InsertAtEnd(&head, -1);
        InsertAtEnd(&head, 111);
        InsertAtEnd(&head, 3);

    Node *middle = head->next->next;

    *head=partitionLinkedList(head,2);
    Print(head);
}