class Solution {
    int n,m;
    vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
    int dfs(vector<vector<int>> &grid,int r,int c){
        grid[r][c]=0;
        int res=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 &&nr<n && nc<m  && grid[nr][nc]==1){
                res+=dfs(grid,nr,nc);
            }
        }
        return res;
         
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};
