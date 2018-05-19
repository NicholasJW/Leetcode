#include "LeetCode.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* first, ListNode* second){
    if(first == NULL && second == NULL) return NULL;
    ListNode* dummy = new ListNode(0);
    ListNode* ans = dummy;
    while(first != NULL || second != NULL){
        if(first==NULL){
            ans->next = new ListNode(second->val);
            second = second->next;
        }else if(second==NULL){
            ans->next = new ListNode(first->val);
            first = first->next;
        }else if(first->val > second->val){
            ans->next = new ListNode(second->val);
            second = second->next;
        }else{
            ans->next = new ListNode(first->val);
            first = first->next;
        }
        ans = ans->next;
    }
    return dummy->next;
}

ListNode* sortList(ListNode* head){
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    int length=0;
    ListNode* cur = head;
    while(cur != NULL){
        length++;
        cur = cur -> next;
    }
    ListNode* secHead = head;
    for(int i=1; i<length/2; i++){
        secHead = secHead->next;
    }    
    ListNode* newHead = secHead -> next;
    secHead -> next = NULL;
    ListNode* first = sortList(head);
    ListNode* second = sortList(newHead);
    ListNode* ans = merge(first, second);    
    return ans;
}

int main(){
    return 0;
}