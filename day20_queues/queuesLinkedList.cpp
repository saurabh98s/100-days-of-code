#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;


void Enqueue(int data)
{
    Node * temp = NULL; //pointer to new Node
    Node *new_node = new Node();
    new_node->data = data;
    temp=new_node;
    if (front == NULL && rear ==NULL)
    {
        front= rear= temp;
    }
    // we need to add a new node to rear
    rear->next=temp; //adding temp at the last
    rear=temp; //updating rear
    

}

void Dequeue() {
    Node * temp = front; //saving the address of front
    if (front == NULL)
    {
        return;
    }
    if (front == rear)
    {
        front=rear=NULL;
    } else
    {
        front=front->next;
    }
    delete(temp);
    
}



void Peek()
{

    Node * temp = front;
    if (temp == NULL)
    {
        cout<<"Nothing to display";
        return;
    }
    cout<<"front data"<<temp->data<<endl;
    

}

void dataAtRear(){
    Node * temp = rear;
    if (temp == NULL)
    {
        cout<<"Nothing to display";
        return;
    }
    cout<<"back data"<<temp->data<<endl;
    
}



int main()
{
    Enqueue(1);
    dataAtRear();
    Peek();
    Enqueue(2);
    dataAtRear();
    Peek();
    Enqueue(3);
    dataAtRear();
    Peek();
    Enqueue(4);
    dataAtRear();
    Peek();
    Dequeue();
    dataAtRear();
    Peek();
    return 0;
}