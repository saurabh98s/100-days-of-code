#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy_head= new ListNode(); //a dummmy node
        ListNode *l3=dummy_head; //pointer to that dummy node
        
        int carry=0; //carry value
        
        while(l1 != NULL || l2!= NULL){ 
            
            
            //null check 0;
            int l1_val = (l1!=NULL)? l1->val:0;
            int l2_val = (l2!=NULL)? l2->val:0; 
            
            //adding the actual value
            int current_sum= l1_val +l2_val+carry;
            carry = current_sum / 10; //carry will hold whats left at one's place
            int lastDigit = current_sum % 10; //same thing at 10s place
            
            ListNode * new_node = new ListNode(); //a new node
            new_node->val=lastDigit; //add the lastDigit to the new node
            l3->next=new_node; //append that node at the end
        
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
            l3=l3->next; //shift it
        }
        
        if(carry >0){ //if the left over carry is greater than 0
            ListNode * new_node = new ListNode();
            new_node->val=carry;
            l3->next=new_node;
            l3=l3->next;
        }
        return dummy_head->next;
    }
};