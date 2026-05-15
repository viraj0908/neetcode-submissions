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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mover=list1;
        priority_queue<int,vector<int>,greater<int>> heap;
        while(mover && mover->next){
            mover=mover->next;
        }
        if(!mover) mover=list2;
        else {
            mover->next=list2;
            mover=list1;
        }
        while(mover){
            heap.push(mover->val);
            mover=mover->next;
        }
        if(!list1) mover=list2;
        else mover =list1;
        while(mover){
            mover->val=heap.top();
            heap.pop();
            mover=mover->next;
        }
        if(list1) return list1;
        else return list2;

    }
};
