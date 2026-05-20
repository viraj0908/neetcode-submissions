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
    int find_sum(TreeNode* node,int sum,int &max_sum){
        if(!node) return 0;
        sum+=node->val;
        max_sum=max(sum,max_sum);
        int left=find_sum(node->left,sum,max_sum);
        int right=find_sum(node->right,sum,max_sum);
        return max_sum;
    }

    int ans=INT_MIN;
    void f(TreeNode* node){
        if(!node) return ;
        int max_sum=0;
        int left=find_sum(node->left,0,max_sum);
        max_sum=0;
        int right=find_sum(node->right,0,max_sum);
        ans=max(ans,node->val+left+right);
        f(node->left);
        f(node->right);
    }
public:
    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};
