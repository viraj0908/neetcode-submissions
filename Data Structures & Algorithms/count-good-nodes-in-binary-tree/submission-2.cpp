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
    void f(TreeNode* node,int max){
        if(!node) return ;
        if(node->val >= max){
            ans++;
            max=node->val;
        }
        f(node->left,max);
        f(node->right,max);
    }
public:
    int goodNodes(TreeNode* root) {
        int max=-1e9;
        f(root,max);
        return ans;
    }
};
