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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        vector<ListNode*> movers(n,nullptr);
        for(int i=0;i<n;i++){
            movers[i]=lists[i];
        }
        ListNode* temp=new ListNode(-1);
        ListNode* nhead=temp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for(int i=0;i<n;i++){
            if(!movers[i]) continue;
            heap.push({movers[i]->val,i});
        }
        while(!heap.empty()){
            int data=heap.top().first;
            int ind=heap.top().second;
            temp->next=movers[ind];
            temp=temp->next;
            movers[ind]=movers[ind]->next;
            heap.pop();
            if(!movers[ind]) continue;
            heap.push({movers[ind]->val,ind});
        }
        temp->next=nullptr;
        nhead=nhead->next;
        return nhead;
    }
};
