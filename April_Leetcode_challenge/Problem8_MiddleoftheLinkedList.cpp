/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode *slow=head,*fast=head,*temp=head;
        int x=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            x++;
        }
        int i=0;
        while(i<x/2)
        {
            slow=slow->next;
            i++;
        }
            return slow;   
    }
};