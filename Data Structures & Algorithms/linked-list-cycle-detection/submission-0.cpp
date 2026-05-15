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
        set<ListNode*> st;
        ListNode* mover=head;
        while(mover){
            if(st.find(mover)!=st.end()){
                return true;
            }
            st.insert(mover);
            mover=mover->next;
        }
        return false;
    }
};
