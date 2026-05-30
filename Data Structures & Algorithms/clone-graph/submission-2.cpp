/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        queue<Node*> q;
        q.push(node);
        map<Node*,Node*> hash;
        Node* cnode=new Node(node->val);
        hash[node]=cnode;
        while(!q.empty()){
            Node* front_node=q.front();
            q.pop();
            for(auto neighbor:front_node->neighbors){
                if(hash.count(neighbor)){
                    hash[front_node]->neighbors.push_back(hash[neighbor]);
                }
                else{
                    Node* cneighbor=new Node(neighbor->val);
                    hash[neighbor]=cneighbor;
                    hash[front_node]->neighbors.push_back(hash[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        return cnode;
    }
};
