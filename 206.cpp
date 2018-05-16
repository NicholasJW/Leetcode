#include "LeetCode.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* reverseList(ListNode* head, ListNode* sec){
    if(sec==NULL){
        return head;
    }
    
    ListNode* nextNode = sec->next;
    sec->next = head;
    return reverseList(sec, nextNode);
}

ListNode* reverseList(ListNode* head){
    if(head==NULL) return NULL;
    ListNode* secondNode = head->next;
    head->next=NULL;
    return reverseList(head, secondNode);
}

int main(){
    return 0;
}