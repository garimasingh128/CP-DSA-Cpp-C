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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=0;
        ListNode* curr=head;
        while(curr){
            k++;
            curr=curr->next;
        }
        int y=k-n;
        ListNode* temp=head;
        int x=0;
        while(temp){
            x++;
            if(x==y){
                temp->next=temp->next->next;
                break;
            }
            temp=temp->next;
        }
        if(y==0) head=head->next;
        return head;
    }
};