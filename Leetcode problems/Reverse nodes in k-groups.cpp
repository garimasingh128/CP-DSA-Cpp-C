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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode* current = head, *new_head = NULL;
        int length = 0;
        while(current != NULL) {
            length++;
            current = current->next;
        }
        ListNode* previous = NULL, *next = NULL, *tail1 = NULL, *tail2 = head;
        current = head;
        while(length >= k) {
            for(int i = 0; i < k; i++) {
                next = current->next;
                current->next = previous;
                previous = current;
                current = next;
            }
            if(new_head == NULL) new_head = previous;
            if(tail1 != NULL) tail1->next = previous;
            tail2->next = current;
            tail1 = tail2;
            tail2 = current;
            previous = NULL;
            length -= k;
        }
        return new_head;
    }
};