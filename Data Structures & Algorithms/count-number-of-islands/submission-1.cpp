class Solution {
    int n,m;
    vector<int> delrow={-1,0,1,0},delcol={0,1,0,-1};
    void bfs(vector<vector<char>> &grid,int srx,int sry){
        queue<pair<int,int>> q;
        grid[srx][sry]='0';
        q.push({srx,sry});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]=='1'){
                    grid[nrow][ncol]='0';
                    q.push({nrow,ncol});
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
