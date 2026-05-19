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
    int f(TreeNode* node,int &ind,int k){
        if(!node) return -1;
        int l=f(node->left,ind,k);
        if(l!=-1){
            return l;
        }
        ind++;
        if(ind==k) return node->val;
        return f(node->right,ind,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ind=0;
        return f(root,ind,k);
        
    }
};
