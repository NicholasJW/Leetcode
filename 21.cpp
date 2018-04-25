#include "LeetCode.h"

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* current = new ListNode(0);
        ListNode* newList = current;
        while(l1!=NULL || l2!=NULL){
            if(l1==NULL){
                current->next = l2;
                l2 = l2->next;
            }else if(l2==NULL){
                current->next = l1;
                l1 = l1->next;
            }else{
                if(l1->val < l2->val){
                    current->next = l1;
                    l1 = l1->next;
                }else{
                    current->next = l2;
                    l2 = l2->next;
                }
            }
            current = current->next;

        }

        return newList->next;
    }

int main(){
    
}
