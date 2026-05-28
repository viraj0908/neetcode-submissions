class Solution {
    vector<vector<int>> dp;
    int n,m;
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
    int f(int i,int j,vector<vector<int>> &matrix){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=0;k<4;k++){
            int nrow=i+dx[k];
            int ncol=j+dy[k];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && matrix[nrow][ncol]>matrix[i][j]) ans=max(ans,f(nrow,ncol,matrix));
        }
        return dp[i][j]=1+ans;
        
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1) ans=max(ans,dp[i][j]);
                else ans=max(ans,f(i,j,matrix));
            }
        }
        return ans;
    }
};
