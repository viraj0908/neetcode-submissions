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
    ListNode* reverse(ListNode* node){
        if(!node || !node->next) return node;
        ListNode* nhead=reverse(node->next);
        ListNode* front=node->next;
        front->next=node;
        node->next=nullptr;
        return nhead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* node1=head,*nodek=head,*nxt=nullptr,*prev=nullptr,*temp=nullptr;
        int cnt=1;
        while(1){
            if(!nodek) {
                if(prev) prev->next=node1;
                break;
            }
            else if(cnt<k){
                cnt+=1;
                nodek=nodek->next;
            }
            else{
                nxt=nodek->next;
                nodek->next=nullptr;
                ListNode* nhead=reverse(node1);
                if(prev) prev->next=nhead;
                else temp=nhead;
                prev=node1;
                node1=nxt;
                nodek=node1;
                cnt=1;
            }
        }
        if(temp) return temp;
        else return head;
    }
};
