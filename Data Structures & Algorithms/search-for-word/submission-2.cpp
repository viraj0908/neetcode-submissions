class Solution {
    bool is_valid(int row,int col,vector<vector<char>> &board){
        int n=board.size();
        int m=board[0].size();
        return row>=0 && col>=0 && row<n && col<m;
    }

    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    bool search(int row,int col,vector<vector<char>> &board,string word,int ind,vector<vector<int>> &visited){
        if(ind==word.size()-1) return true;
        visited[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(!is_valid(nrow,ncol,board)) continue;
            // if(nrow==px && ncol==py) continue;
            if(visited[nrow][ncol]) continue;
            if(board[nrow][ncol]==word[ind+1]){
                if(search(nrow,ncol,board,word,ind+1,visited)) return true;
            }
        }
        visited[row][col]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vector<vector<int>> visited(n,vector<int>(m,0));
                    if(search(i,j,board,word,0,visited)) return true;
                }
            }
        }
        return false;
    }
};
