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
    bool f(TreeNode* node,int lo,int hi){
        if(!node) return true;
        return node->val<hi && node->val>lo && f(node->left,lo,node->val) && f(node->right,node->val,hi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root,INT_MIN,INT_MAX);
        
    }
};
