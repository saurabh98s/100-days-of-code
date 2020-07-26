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
Node* Insert(int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
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
    head=NULL;
    for(int i=0;i<5;i++){
        head=Insert(i);
    } 
    Print(head);
}