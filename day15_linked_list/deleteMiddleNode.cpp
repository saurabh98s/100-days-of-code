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

void deleteMiddleNode(Node *middle)
{
    if (middle==NULL||middle->next==NULL)
    {
        return;
    }
    middle->data=middle->next->data;
    middle->next=middle->next->next;
}

int main()
{
    head = NULL; //since this is already pointer to Node
    for (int i = 0; i < 5; i++)
    {
        InsertAtEnd(&head, i); //we will pass the value by reference
    }                          //this will change the value of head;
     Print(head);
    cout << "Before Find kth from last\n";
    Node* middle=head->next->next;
    
    deleteMiddleNode(middle);
    Print(head);
}