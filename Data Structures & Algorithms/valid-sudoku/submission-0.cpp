class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> row(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int n=board[i][j]-'0';
                    if(row[n]) return false;
                    else row[n]=1;
                }
            }   
        }
        for(int i=0;i<9;i++){
            vector<int> col(10,0);
            for(int j=0;j<9;j++){
                // if(board[j][i]<='1' || board[j][i]>='9') continue
                if(board[j][i]=='.') continue;
                int n=board[j][i]-'0';
                if(col[n]) return false;
                else col[n]=1;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> box(10,0);
                for(int m=i;m<i+3;m++){
                    for(int n=j;n<j+3;n++){
                        if(board[m][n]=='.') continue;
                        int num=board[m][n]-'0';
                        if(box[num]) return false;
                        else box[num]=1;
                    }
                }
            }
        }
        return true;
        
    }
};
