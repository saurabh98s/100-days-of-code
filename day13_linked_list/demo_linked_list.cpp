#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head; //global

void Insert(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    // if (head!=NULL)
    // {
    //     temp->next=head;
    // }

    head = temp; //head points to temp;
}

void Print()
{
    Node *temp = head; //points to head
    cout<<"List is :";
    while (temp!=NULL) //goes on till the end of list
    {
        cout<<" ",temp->data;
        temp=temp->next;
    }
    cout<<"\n";
    
}

// push appends at the beginning
int main()
{
    head = NULL; //points no where
    cout << "insert numbers\n";
    int n, i, x;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "enter the number";
        cin >> x;
        Insert(x);
        Print();
    }
}