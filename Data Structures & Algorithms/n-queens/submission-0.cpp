class Solution {
    void vh_mark(vector<vector<int>> &visited,int row,int col,int val){
        for(int i=0;i<visited.size();i++){
            visited[i][col] +=val;
            if(visited[i][col]<0) visited[i][col]=0;
            visited[row][i]+=val;
            if(visited[row][i]<0) visited[row][i]=0;
            
        }
        return ;
    }
    void dd_mark(vector<vector<int>> &visited,int row,int col,int val){
        int n=visited.size();
        for(int i=-n;i<=n;i++){
            int nrow=row+i;
            int ncol=col+i;
            if(nrow>=0 && ncol>=0 && nrow<visited.size() && ncol<visited.size()){
                visited[nrow][ncol]+=val;
                if(visited[nrow][ncol]<0) visited[nrow][ncol]=0;
            }
        }
        for(int i=-n;i<=n;i++){
            int nrow=row-i;
            int ncol=col+i;
            if(nrow>=0 && ncol>=0 && nrow<visited.size() && ncol<visited.size()){
                visited[nrow][ncol]+=val;
                if(visited[nrow][ncol]<0) visited[nrow][ncol]=0;
            }
        }
        return;
        
    }

    vector<vector<string>> res;
    void f(vector<string> &ans,vector<vector<int>> &visited,int ind){
        if(ind==ans.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<ans.size();i++){
            if(visited[i][ind]) continue;
            ans[i][ind]='Q';
            vh_mark(visited,i,ind,1);
            dd_mark(visited,i,ind,1);
            f(ans,visited,ind+1);
            ans[i][ind]='.';
            vh_mark(visited,i,ind,-1);
            dd_mark(visited,i,ind,-1);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++){
            str+='.';
        }
        vector<string> ans(n,str);
        vector<vector<int>> visited(n,vector<int> (n,0));
        f(ans,visited,0);
        return res;
    }
};
