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
    void reorderList(ListNode* head) {
        if(!head) return;
        map<int,ListNode*> hash;
        ListNode* mover=head;
        int ind=0;
        while(mover){
            hash[ind]=mover;
            ind++;
            mover=mover->next;
        }
        int n=hash.size();
        int left=0,right=n-1,k=1;
        ListNode* temp=new ListNode(-1);
        ListNode* nhead=temp;
        while(left<=right){
            if(k==1){
                temp->next=hash[left];
                temp=hash[left];
                left+=1;
            }
            else{
                temp->next=hash[right];
                temp=hash[right];
                right-=1;
            }
            k*=-1;
        }
        temp->next=nullptr;
        head=nhead->next;
        return;
        

    }
};
