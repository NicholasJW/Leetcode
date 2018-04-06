#include <iostream>
#include <string>
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k){
    stack<ListNode*> ct;
    ListNode* in = head;
    for(int i=0; i<k; i++){
        if(in == NULL)
            return head;
        ct.push(in);
        in = in->next;
        // cout << ct.size() << endl;
    }
    ListNode* newHead = ct.top();
    ListNode* out;
    while(ct.size() != 0){
        out = ct.top();
        // cout << out->val << endl;
        ct.pop();
        if(ct.size() > 0)
            out->next = ct.top();
        else
            out->next = nullptr;
    }
    out->next = reverseKGroup(in, k);
    return newHead;
}

int main(){
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* newH = reverseKGroup(&n1, 2);
    for(int i=0; i<5; i++){
        cout << newH->val << endl;
        newH = newH->next;
    }
}
