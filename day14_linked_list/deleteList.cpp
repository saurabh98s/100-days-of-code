#include<iostream>
#include<string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    string name;
    Node* head;
};
struct Node* head;

void InsertatHead(Node** head,int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=NULL;
    if (head!=NULL) 
    {
        temp->next=*head;
    }
    *head=temp;
}

// void InsertAtNth(Node** head,int x) {
//     Node* temp=new Node();
//     temp->data=x;
//     temp->next=NULL;
//     if (x ==1)
//     {
//      *head=temp;
//     }
//     for (int i = 0; i < x-1; i++)
//     {
//         *head=
//     }
    
    

// }

void InsertAtEnd(Node **head,int x ) {
    Node* temp=new Node();
    temp->data=x;
    Node *last=*head;
    
    if (*head==NULL)
    {
        *head=temp;
        return;
    }
    
    while (last->next!=NULL)
    {
        last=last->next;
    }
    temp->next=NULL;
    last->next=temp;
    return;
    
}

void DeleteNodeNth(int pos) {
    Node* temp1=head; //points to head
    if (pos==1)
    {
        head=temp1->next;
        delete(temp1);
        return;
    }
    for (int i = 0; i < pos; i++)
    {
        temp1=temp1->next; //
    }
    Node* temp2= temp1->next; //nth node
        temp1->next=temp2->next; //n+1 node
        delete(temp2);
}

void Print(Node* head)
{
    // Node* temp=head;
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }  
     
}

int main(){
    head=NULL; //since this is already pointer to Node
    // head=NULL; //since this is already pointer to Node
    for(int i=0;i<5;i++){
        InsertAtEnd(&head,i); //we will pass the value by reference
    }  //this will change the value of head;
    // DeleteNodeNth(2);
    // DeleteNodeNth(1);
    Print(head);
}