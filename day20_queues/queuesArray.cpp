#include<iostream>
#include<vector>
#define MAX 10

using namespace std;

class MyQueue {

    private:
        int A[MAX];
    
        int front,rear;

    public:
        MyQueue(){
            front=rear=-1;
        }

        bool IsEmpty(){
            if (front==-1 && rear==-1)
            {
                return true;
            } else
            {
                return false;
            }    
        }


        void Push(int x){
            if(rear == MAX-1){
                return; //check if full or not
            } else if(IsEmpty())
            {
                front = rear=0; //point to first index;
                 A[rear]=x; //assign value to rear
            } else
            {
                rear+=1; //increase rear by 1
                 A[rear]=x; //assign value to rear
            }
           
            cout<<"Added value to rear: "<<x<<endl;
            
        }

        void Pop(){
            cout<<"Deleted: "<<A[front]<<endl;
            if (IsEmpty())
            {
                return;
            } else if (front==rear) //this delete operation will empty the queue
            {
                front=rear=-1;
            } else
            {
                front+=1;
            } 
        }

        void Peek(){
            if (IsEmpty())
            {
                return;
            } else
            {
                cout<<"Top of the queue: "<<A[front]<<endl;
            }
        }
        void Print(){
            if (IsEmpty())
            {
                return;
            } else
            {
                for (int i = front; i < rear; i++)
                {
                    cout<<A[i];
                }
                cout<<endl;
                
            }
            
            
        }
};

int main() {


    MyQueue S;

    S.Push(1);S.Print();
    S.Push(2);S.Print();
    S.Push(3);S.Print();
    S.Push(4);S.Print();
    S.Push(5);S.Print();
    S.Push(6);S.Print();
    S.Pop();S.Print();
    S.Peek();
    
    




}

