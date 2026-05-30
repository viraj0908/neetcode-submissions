class Solution {
    int n,m;
    vector<int> delrow={-1,0,1,0},delcol={0,1,0,-1};
    void bfs(vector<vector<int>> &grid,int x,int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=-1){
                    if(grid[nr][nc]>grid[r][c]+1){
                        grid[nr][nc]=grid[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    bfs(grid,i,j);
                }
            }
        }
        return;
    }
};
