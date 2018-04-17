#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* ans;
    if(l1 == NULL){
        l1 = new ListNode(0);
    }
    if(l2 == NULL){
        l2 = new ListNode(0);
    }
    // Base case
    if(l1->next==NULL && l2->next==NULL){
        int value=l1->val+l2->val;
        ans->val=value%10;
        if(value>10){
            // ListNode* next = new ListNode(1);
            ans->next = new ListNode(1);
        }
        return ans;
    }

    int value=l1->val+l2->val;
    ans->val=value%10;
    if(value>10){
        l1->next->val++;
    }
    ans->next = addTwoNumbers(l1->next, l2->next);
    return ans;
}