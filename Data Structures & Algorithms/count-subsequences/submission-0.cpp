class Solution {
    vector<vector<int>> dp;
    int f(string s,string t,int i,int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j]= f(s,t,i+1,j+1)+f(s,t,i+1,j);
        }
        else return dp[i][j]= f(s,t,i+1,j);
    }
public:
    int numDistinct(string s, string t) {
        dp.resize(s.size(),vector<int>(t.size(),-1));
        return f(s,t,0,0);
    }
};
