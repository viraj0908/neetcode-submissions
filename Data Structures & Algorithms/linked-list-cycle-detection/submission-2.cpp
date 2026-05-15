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
    bool hasCycle(ListNode* head) {
        if(!head) return false;
        ListNode* mover=head;
        mover->val=INT_MIN;
        mover=mover->next;
        while(mover){
            if(mover->val==INT_MIN){
                return true;
            }
            mover->val=INT_MIN;
            mover=mover->next;
        }
        return false;
    }
};
