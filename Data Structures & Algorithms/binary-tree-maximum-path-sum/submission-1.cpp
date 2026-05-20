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
    int res=INT_MIN;
    int f(TreeNode* node){
        if(!node) return 0;
        int left=max(0,f(node->left));
        int right=max(0,f(node->right));
        res=max(res,left+right+node->val);
        return node->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        return res;
    }
};
