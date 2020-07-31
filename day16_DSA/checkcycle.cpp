#include<iostream>
#include<map>
using namespace std;

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>checkMap;
        while(head!=NULL){
            if (checkMap[head]) {
            return true;
            } else {
                checkMap[head]=true;    
            }
            
            head=head->next;
        }
        return false;
        
    }