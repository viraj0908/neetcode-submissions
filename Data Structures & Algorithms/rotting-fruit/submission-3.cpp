class Solution {
    int n,m;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    grid[i][j]=0;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int t=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    q.push({t+1,{nr,nc}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
