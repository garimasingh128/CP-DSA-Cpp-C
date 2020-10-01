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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* list = new ListNode (1);
        ListNode* current = list;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) 
                current = current -> next = new ListNode (l1 -> val), l1 = l1 -> next;
            else if (l1 -> val > l2 -> val)
                current = current -> next = new ListNode (l2 -> val), l2 = l2 -> next;
            else {
                current = current -> next = new ListNode (l1 -> val), l1 = l1 -> next;
                current = current -> next = new ListNode (l2 -> val), l2 = l2 -> next;
            }
        }
        while (l1 != NULL) current = current -> next = new ListNode (l1 -> val), l1 = l1 -> next;
        while (l2 != NULL) current = current -> next = new ListNode (l2 -> val), l2 = l2 -> next;
        return list -> next;
    }
};