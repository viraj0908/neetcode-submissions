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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        ListNode* t1=l1,*t2=l2;
        int cy=0;
        while(1){
            int d=cy;
            if(!t1 && !t2) break;
            else if(!t1 && t2) {
                if(t2->val+cy<=9) {
                    d+=t2->val;
                    cy=0;
                }
                else{
                    d+=(t2->val);
                    d=(d%10);
                    cy=1;
                }
            }
            else if(t1 && !t2) {
                if(t1->val+cy<=9) {
                    d+=t1->val;
                    cy=0;
                }
                else{
                    d+=(t1->val);
                    d=(d%10);
                    cy=1;
                }
            }
            else{
                int x=t1->val+t2->val;
                if(x+cy<=9) {
                    d+=x;
                    cy=0;
                }
                else {
                    d+=(x%10);
                    cy=1;
                }
            }
            ListNode* t=new ListNode(d);
            temp->next=t;
            temp=t;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(cy==1){
            ListNode* t=new ListNode(1);
            temp->next=t;
        }
        head=head->next;
        return head;
    }
};
