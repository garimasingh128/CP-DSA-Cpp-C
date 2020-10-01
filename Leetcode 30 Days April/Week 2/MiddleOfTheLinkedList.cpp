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

        ListNode* a=head;
        ListNode* b=head;

        while(b->next!=NULL)
        {
            a=a->next;
            if(b->next->next==NULL)
                b=b->next;
            else
                b=b->next->next;
        }
        return a;

    }
};
