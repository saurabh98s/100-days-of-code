#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* link;
};

Node * top = NULL;

void Push(int x){
    Node * new_node = new Node();
    new_node->data=x;
        new_node->link=top;
        top=new_node;
}

void Pop() {
    Node *temp;
    if (top ==NULL)
    {
        return;
    }
    temp=top;
    top=top->link;
    delete(temp);
    
}

void Print()  
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout << "\nStack Underflow"; 
        exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            cout <<  temp->data << " "; 
  
            // assign temp link to temp 
            temp = temp->link; 

        }
        cout<<"\n"; 
    }
    
}



int main() {
    Push(1);Print();
    Push(2);Print();
    Push(3);Print();
    Push(4);Print();
    Pop();Print();
}