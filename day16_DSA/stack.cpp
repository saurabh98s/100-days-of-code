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

void push(int val) {
    // if head is null or not null it will always go into the head pointers location
    Node * new_node = new Node();
    new_node->data=val; //assigns value to new_node
    new_node->next=head; //points to where head was pointing
    head=new_node;
}

void pop() {
    if (head==NULL)
    {
        cout<<"stack underflow"<<endl;
    } else
    {
        cout<<"Popped data is"<<head->data<<endl;
        head=head->next;

    }
    
    
}

int main()
{
    head = NULL; //since this is already pointer to Node
    for (int i = 0; i < 5; i++)
    {
       push(i);
    }                          //this will change the value of head;    
    Print(head);
    pop();
    Print(head);
    pop();
    Print(head);
    pop();
    Print(head);pop();
    Print(head);pop();
    Print(head);
    pop();
    Print(head);
}