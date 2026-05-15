/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* nhead=new Node(head->val);
        Node* mover=head->next;
        Node* temp=nhead;
        unordered_map<Node*,Node*> hash;
        while(mover){
            Node* t=new Node(mover->val);
            temp->next=t;
            temp=t;
            mover=mover->next;
        }
        mover=head;
        temp=nhead;
        while(mover){
            hash[mover]=temp;
            mover=mover->next;
            temp=temp->next;
        }
        mover=head;
        temp=nhead;
        while(mover){
            temp->random=hash[mover->random];
            mover=mover->next;
            temp=temp->next;
        }
        return nhead;

    }
};
