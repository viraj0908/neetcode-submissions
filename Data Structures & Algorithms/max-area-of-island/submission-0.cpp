class Solution {
    int n,m;
    vector<int> delrow={-1,0,1,0},delcol={0,1,0,-1};
    int bfs(vector<vector<int>> &grid,int x,int y){
        queue<pair<int,int>> q;
        int area=0;
        q.push({x,y});
        grid[x][y]=0;
        while(!q.empty()){
            int count=q.size();
            area+=count;
            for(int i=0;i<count;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nrow=row+delrow[j];
                    int ncol=col+delcol[j];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                        grid[nrow][ncol]=0;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=bfs(grid,i,j);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};
