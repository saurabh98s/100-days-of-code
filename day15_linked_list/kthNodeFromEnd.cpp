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

void returnKthElementFromLast(Node *head,int k)
{
    Node* dummy_head=head;
    Node* p=dummy_head;
    Node* q=dummy_head;

    for (int i = 0; i <= k; i++)
    {
        q=q->next;
    }

    while (q!=NULL)
    {
        
        p=p->next;
        q=q->next;
        
    }
    cout<<"Kth from the last is"<<p->data<<endl;
 
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
    returnKthElementFromLast(head,0);
    returnKthElementFromLast(head,1);
    returnKthElementFromLast(head,2);
    returnKthElementFromLast(head,3);
}