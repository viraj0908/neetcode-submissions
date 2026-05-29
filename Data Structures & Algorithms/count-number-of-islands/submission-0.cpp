class Solution {
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &visited,int sx,int sy){
        queue<pair<int,int>> q;
        q.push({sx,sy});
        visited[sx][sy]=1;
        vector<int> delrow={-1,0,1,0},delcol={0,1,0,-1};
        int n=visited.size();
        int m=visited[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
