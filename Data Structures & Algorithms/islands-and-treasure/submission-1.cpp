class Solution {
    int inf=INT_MAX;
    int n,m;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,int>> q;
        vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==inf){
                    grid[nr][nc]=grid[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return;
    }
};
