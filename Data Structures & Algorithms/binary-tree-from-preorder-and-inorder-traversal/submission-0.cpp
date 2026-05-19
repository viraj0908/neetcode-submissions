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
    int find_root(vector<int> &preorder,vector<int> &inorder){
        int ind=0;
        while(1){
            if(inorder[ind]==preorder[0]) {
                return ind;
            }
            ind++;
        }
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        int ind=find_root(preorder,inorder);
        int root_val=inorder[ind];
        TreeNode* root=new TreeNode(root_val);
        vector<int> li,lp;
        for(int i=0;i<ind;i++){
            li.push_back(inorder[i]);
        }
        for(int i=1;i<=ind;i++){
            lp.push_back(preorder[i]);
        }
        root->left=buildTree(lp,li);
        vector<int> ri,rp;
        for(int i=ind+1;i<inorder.size();i++){
            ri.push_back(inorder[i]);
        }
        for(int i=ind+1;i<preorder.size();i++){
            rp.push_back(preorder[i]);
        }
        root->right=buildTree(rp,ri);
        return root;
    }
};
