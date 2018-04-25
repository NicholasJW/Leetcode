#include "LeetCode.h"

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node){
    ListNode* current = node;
    ListNode* prev = NULL;
    while(current->next != NULL){
        current->val = current->next->val;
        prev = current;
        current = current->next;
    }
    prev->next=NULL;
}

int main(){

}
