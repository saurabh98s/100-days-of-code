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
void Insert(int x){
    Node* temp=new Node();
    temp->data=x;
    temp->next=head;
    head=temp;
}

void Print()
{
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
}

int main(){
    head=NULL;
    for(int i=0;i<5;i++){
        Insert(i);
    } 
    Print();
}