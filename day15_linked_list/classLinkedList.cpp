#include<iostream>
using namespace std;

class MyLinkedList {
    struct node {
        int val;
        node* next;
    };
    node* head;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size || index<0){
            return 0;
        }
        node * cur=head;
        while(index--){
            cur=cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node * temp=new node();
        temp->val=val;
        if(head==NULL){
            head=temp;
            ++size;
        } else {
            temp->next=head;
            head=temp;
            ++size;
        }
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node* traverse = new node;
    traverse = head;
    while(traverse->next != NULL)
        traverse = traverse->next;
    node* cur = new node;
    cur->val = val;
    // cout<<"Adding "<<val<<endl;
    cur->next = NULL;
    traverse->next = cur;
    ++size;
    // cout<<size<<endl;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size || index < 0)
        return;
    else if(index == 0){
        addAtHead(val);
        return;
    }
    else if(index == size){
        addAtTail(val);
        return;
    }
    node* traverse = new node;
    traverse = head;
    while(index != 1){
        traverse= traverse->next;
        index--;
    }
    node* cur = new node;
    cur->val = val;
    // cout<<"Adding "<<val<<endl;
    cur->next = traverse->next;
    traverse->next = cur;
    ++size;
    // cout<<size<<endl;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
         if(index >= size || index < 0)
        return;
    else if(index == 0){
        head = head->next;
        --size;
        return;
    }
    node* traverse = new node;
    traverse = head;
    for(int i = 0; i < index-1; ++i)
        traverse = traverse->next;
    // cout<<"Deleting "<<traverse->next->val<<endl;
    traverse->next = traverse->next->next;
    --size;
    // cout<<size<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */