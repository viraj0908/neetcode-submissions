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
    void dfs1(Node* node,map<Node*,Node*> &hash,vector<int> &visited){
        if(!node) return;
        visited[node->val] =1;
        Node* cnode=new Node(node->val);
        hash[node]=cnode;
        for(auto neighbor:node->neighbors){
            if(!visited[neighbor->val]){
                dfs1(neighbor,hash,visited);
            }
        }
        return;
    }

    void dfs2(Node* node,map<Node*,Node*> &hash,vector<int> &visited){
        if(!node) return;
        visited[node->val]=1;
        Node* cnode=hash[node];
        for(auto neighbor:node->neighbors){
            cnode->neighbors.push_back(hash[neighbor]);
            if(!visited[neighbor->val]){
                dfs2(neighbor,hash,visited);
            }
        }
        return;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*> hash;
        vector<int> visited(101,0);
        dfs1(node,hash,visited);
        for(int i=0;i<visited.size();i++) visited[i]=0;
        dfs2(node,hash,visited);
        return hash[node];
    }
};
