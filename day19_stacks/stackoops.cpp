#include<iostream>

using namespace std;

#define MAX_SIZE 100

class Stack
{
private:
    int A[MAX_SIZE];
    int top;
public:
    // Default Constructor.
    Stack() {
        // set value to required elements
        top = -1; // for empty array
    }

    void Push(int x){
        if (top ==MAX_SIZE-1)
        {
            cout<<"[ERROR] Overflow\n";
            return;
        }
        A[++top]=x;
        
    }

    void Pop(){
        if (top==-1)
        {
            cout<<"[ERROR] Nothing to Pop\n";
        }
        top--;
        
    }

    // Top operation to return element at top of stack. 
	int Top() 
	{
		return A[top];
	}
 
	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
		if(top == -1) return 1;
		return 0;
	}

	// ONLY FOR TESTING - NOT A VALID OPERATION WITH STACK 
	// This function is just to test the implementation of stack. 
	// This will print all the elements in the stack at any stage. 
	void Print() {
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",A[i]);
		printf("\n");
	}

};

int main(){
   // Code to test the implementation. 
    // calling Print() after each push or pop to see the state of stack. 
    Stack S;
    S.Push(2);S.Print();
    S.Push(3);S.Print();
    S.Push(4);S.Print();
    S.Pop();S.Print();

}
