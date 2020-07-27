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

void deleteDups(Node* node) {

    map
}

// void InsertAtEnd(Node **head,int x ) {
//     Node* temp=new Node();
//     temp->data=x;
//     Node *last=*head;
//     temp->next=NULL;
//     if (*head==NULL)
//     {
//         *head=temp;
//         return;
//     }
    
//     while (last->next!=NULL)
//     {
//         last=last->next;
//     }
//     last->next=temp;
//     return;
    
// }

// void Print(Node* head)
// {
//     // Node* temp=head;
//     while (head!=NULL)
//     {
//         cout<<head->data<<"->";
//         head=head->next;
//     }
    
// }

int main(){
    head=NULL; //since this is already pointer to Node
    for(int i=0;i<5;i++){
        InsertatHead(&head,i); //we will pass the value by reference
    }  //this will change the value of head;
    // Print(head);
    // head=NULL; //since this is already pointer to Node
    // Print(head);
}