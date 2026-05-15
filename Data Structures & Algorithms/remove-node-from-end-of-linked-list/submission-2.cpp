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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* mover=head;
        int count=0;
        while(mover){
            count+=1;
            mover=mover->next;
        }
        int ind=count-n;
        if(ind==0) {
            head=head->next;
            return head;
        }
        count=0;
        mover=head;
        while(count<ind-1){
            mover=mover->next;
            count+=1;
        }
        cout<<mover->val<<endl;
        ListNode* prev=mover;
        ListNode* nxt=mover->next;
        nxt=nxt->next;
        prev->next=nxt;
        return head;
         
    }
};
