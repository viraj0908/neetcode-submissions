class Solution {
    int inf=INT_MAX;
    int n,m;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> distance(n,vector<int>(m,inf));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({i,j});
                    distance[i][j]=0;
                    }
            }
        }

        vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && distance[nr][nc]==inf){
                    distance[nr][nc]=distance[r][c]+1;
                    q.push({nr,nc});
                }
            }
            
            }
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0 || grid[i][j]==2) continue;  
                    if(grid[i][j]==1){
                        if(distance[i][j]==inf) return -1;
                        else ans=max(ans,distance[i][j]);
                    }
                }
            }
            return ans;
    }
};
