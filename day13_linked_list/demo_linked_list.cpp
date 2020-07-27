#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *previous;
};
//  Node *head; //global

Node *Insert(Node *head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp; //head points to temp;
    return head;
}

void insertNodeAtEnd(Node ** head, int data)
{
   Node* new_node= new Node();
   Node *last=*head;
   new_node->data=data;
   
   if (*head==NULL)
   {
       *head=new_node;
       cout<<"Head: Inserted at the end\n";
       return;
   }
   while (last->next!=NULL)
   {
       last=last->next;
   }
   last->next=new_node;
   new_node->next=NULL; //to be appended at the last shouldn't be pointing anywhere.
   cout<<"Inserted at the end";
   return;
   
}




void Print(Node *head)
{
    cout << "List is :";
    while (head != NULL) //goes on till the end of list
    {
        cout << " " << head->data;
        head = head->next;
    }
    cout << "\n";
}






// push appends at the beginning
int main()
{
    Node *head = NULL; //points no where
    Node *end = NULL; //points no where
    cout << "insert numbers\n";
    int n, i, x;
    cin >> n;
    insertNodeAtEnd(&head,5);
    for (i = 0; i < n; i++)
    {
        cout << "enter the number";
        cin >> x;
        head = Insert(head, x);
        Print(head);
        
        // Print(x);
    }
    // insertNodeAtEnd(5);
        Print(head);
}