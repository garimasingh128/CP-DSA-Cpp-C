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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int,vector<int>,greater<int>> pq;
        ListNode* temp;
        for(int i=0;i<lists.size();i++){
            temp=lists[i];
            while(temp!=NULL){
                pq.push(temp->val);
                temp=temp->next;
            }
        }
        if(pq.empty()) return NULL;
        ListNode* head=new ListNode(pq.top());
        pq.pop();
        temp=head;
        while(!pq.empty()){
            temp->next=new ListNode(pq.top());
            pq.pop();
            temp=temp->next;
        }
        return head;
    }
};