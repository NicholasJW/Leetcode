#include "LeetCode.h"

bool hasCycle(ListNode* head){
    ListNode* fast=new ListNode(2);
    fast->next = head;
    ListNode* slow=new ListNode(1);
    slow->next = head;

    while(fast!=NULL && slow!=NULL){
        if(fast->val == slow->val)
            return true;
        
        if(fast->next != NULL)
            fast = fast->next->next;
        else
            return false;
        slow = slow->next;
    }

    return false;
}

int main(){
}
