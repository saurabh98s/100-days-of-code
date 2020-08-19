#include<iostream>
#include<stack>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node * head = NULL;

void Reverse(){
    Node * head_pt=head;
    stack<Node *>stck;
    while (head_pt!= NULL)
    {
        stck.push(head_pt);
        head_pt=head_pt->next;
    }

    Node * temp =stck.top();
        head = temp;
        stck.pop();

    while (!stck.empty())
    {
        temp->next=stck.top();
        stck.pop();
        temp=temp->next;
    } 
    
}


int main() {
}