/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int ans=0;
    void f(TreeNode* node,map<TreeNode*,int> &hash,int max){
        if(!node) return ;
        if(node->val >= max){
            ans++;
            hash[node]=node->val;
            max=node->val;
        }
        else hash[node]=max;
        f(node->left,hash,max);
        max=hash[node];
        f(node->right,hash,max);

    }
public:
    int goodNodes(TreeNode* root) {
        map<TreeNode*,int> hash;
        f(root,hash,-1e9);
        return ans;
    }
};
