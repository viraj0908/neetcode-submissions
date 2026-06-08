class Solution {
    vector<int> ans;
    void f(vector<vector<int>> &matrix,int top,int down,int left,int right){
        if(left > right || top > down) return;
        if(left==right) {
            for(int i=top;i<=down;i++){
                ans.push_back(matrix[i][left]);
            }
            return;
        }
        else if(top==down){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            return ;
        }
        for(int i=left;i<right;i++){
            ans.push_back(matrix[top][i]);
        }
        for(int i=top;i<down;i++){
            ans.push_back(matrix[i][right]);
        }
        for(int i=right;i>left;i--){
            ans.push_back(matrix[down][i]);
        }
        for(int i=down;i>top;i--){
            ans.push_back(matrix[i][left]);
        }
        f(matrix,top+1,down-1,left+1,right-1);
        return;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        f(matrix,0,n-1,0,m-1);
        return ans;
    }
};
