#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *p = head->next;
        ListNode *q = head;
        while(p){
            if(p->val != q->val){
                p = p->next;
                q = q->next;
            }
            else{
                q->next = p->next;
                p = p->next;
            }
        }
        return head;
    }
};