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
    int minval(TreeNode* node){
        if(!node) return INT_MAX;
        TreeNode* temp=node;
        while(temp->left){
            temp=temp->left;
        }
        return temp->val;
    }

    int maxval(TreeNode* node){
        if(!node) return INT_MIN;
        TreeNode* temp=node;
        while(temp->right){
            temp=temp->right;
        }
        return temp->val;
        
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        int mini=minval(root->right);
        int maxi=maxval(root->left);
        return root->val<mini && root->val> maxi;
    }
};
