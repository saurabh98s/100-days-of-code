#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
// Node *head; //global

Node* Insert(Node* head,int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head!=NULL)
    {
        temp->next=head;
    }
    head = temp; //head points to temp;
    return head;
}

void Print(Node* head)
{
    cout<<"List is :";
    while (head!=NULL) //goes on till the end of list
    {
        cout<<" "<<head->data;
        head=head->next;
    }
    cout<<"\n";
    
}

// push appends at the beginning
int main()
{
    Node* head = NULL; //points no where
    cout << "insert numbers\n";
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "enter the number";
        cin >> x;
        head=Insert(head,x);
        Print(head);
    }
}