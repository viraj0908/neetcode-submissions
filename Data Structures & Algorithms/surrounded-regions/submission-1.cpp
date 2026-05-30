class Solution {
    int n,m;
    vector<int> dr={-1,0,1,0},dc={0,1,0,-1};
    void bfs(vector<vector<char>> &board,vector<vector<int>> &visited,queue<pair<int,int>> &q){
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='O' && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                visited[i][0]=1;
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        bfs(board,visited,q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
        return;
    }
};
