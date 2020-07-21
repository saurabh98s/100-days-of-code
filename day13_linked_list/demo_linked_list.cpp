#include<iostream>
#include<unordered_map>
#include<random>

using namespace std;


// struct Node {
//     int data=0;
//     Node *next=NULL;
// };

// Node *A=NULL; //to point to head, single node

// void insert(Node * & head, int data) {

// }

struct Node
{
    int data;
    Node *next;
};


int main(){

    Node* A;
    A=NULL;
    Node *temp = new Node(); //preferred over the malloc func to allocate memory
    temp->data=2;
    temp->next=NULL; //since this is last node
    A=temp;    
    temp=new Node();
    temp->data=4;
    temp->next=NULL;
    Node* temp1=A;
    while (temp1->next!=NULL)
    {
        cout<<temp->data;
        temp1=temp1->next;
    }
    
}

