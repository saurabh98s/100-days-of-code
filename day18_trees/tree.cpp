#include<iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// dynamic creation happens in heap.
// cant have name or identifier
//accessible by pointer

// Creating a new Node with some data
BSTNode* GetNewNode(int data) {
    BSTNode* newNode = new BSTNode();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}



BSTNode* Insert(BSTNode* root, int data) {
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data<= root->data) {
        root->left=Insert(root->left, data);
    }
    else
    {
        root->right=Insert(root->right, data);
    }
    return root;



}

bool Search(BSTNode* root , int data) {
    if (root==NULL)
    {
        return false;
    } else if (root->data==data)
    {
        return true;
    }
     
    else if(data<=root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
    
    
    
}

int main() {
    // we will know the address of root node;
    // empty tree
    BSTNode* rootPtr=NULL;
    rootPtr= Insert(rootPtr, 1);
    rootPtr= Insert(rootPtr, 2);
    rootPtr= Insert(rootPtr, 3);
    rootPtr= Insert(rootPtr, 4);
    rootPtr= Insert(rootPtr, 5);
    rootPtr= Insert(rootPtr, 59);
    int number;
    cout<<"ENter number to search"<<endl;
    cin>>number;
    if (Search(rootPtr,number)==true)
    {
        cout<<"Found";
    }
    else
    {
        cout<<"NOt found";
    }
    
}