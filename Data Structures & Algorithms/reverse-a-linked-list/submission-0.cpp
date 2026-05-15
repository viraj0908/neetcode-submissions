/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* temp=new ListNode(head->val);
        ListNode* mover=head->next;
        while(mover){
            ListNode* t=new ListNode(mover->val);
            t->next=temp;
            temp=t;
            mover=mover->next;
        }
        return temp;
    }
};
