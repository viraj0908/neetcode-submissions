class Solution {
    int n,m;
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
    void dfs(vector<vector<char>> &grid,int x,int y){
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]=='1'){
                dfs(grid,nx,ny);
            }
        }
        return ;
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
