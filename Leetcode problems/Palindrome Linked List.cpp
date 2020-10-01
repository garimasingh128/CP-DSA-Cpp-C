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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        queue<int> q;
        while(head){
            s.push(head->val);
            q.push(head->val);
            head = head->next; 
        }
        while(!q.empty()){
            int x = q.front();
            int y = s.top();
            if(x!=y) return false;
            s.pop();
            q.pop();
        }
        return true;
    }
};