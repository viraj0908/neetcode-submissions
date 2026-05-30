class Solution {
    int n,m;
    vector<int> delrow={-1,0,1,0},delcol={0,1,0,-1};
    void bfs(vector<vector<int>> &heights,vector<vector<int>> &ocean,queue<pair<int,int>> &q){
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && heights[nrow][ncol]>=heights[row][col] && !ocean[nrow][ncol]){
                    ocean[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }

        }
        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        queue<pair<int,int>> q1,q2;
        for(int i=0;i<m;i++){
            q1.push({0,i});
            pacific[0][i]=1;
            q2.push({n-1,i});
            atlantic[n-1][i]=1;
        }
        for(int i=0;i<n;i++){
            q1.push({i,0});
            pacific[i][0]=1;
            q2.push({i,m-1});
            atlantic[i][m-1]=1;
        }
        bfs(heights,pacific,q1);
        bfs(heights,atlantic,q2);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
