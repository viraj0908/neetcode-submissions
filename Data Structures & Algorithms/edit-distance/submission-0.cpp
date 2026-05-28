class Solution {
    vector<vector<int>> dp;
    string s1,s2;
    int f(int i,int j){
        if(i==s1.size() ) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= f(i+1,j+1);
        else return dp[i][j]= 1+min(f(i+1,j),min(f(i,j+1),f(i+1,j+1)));
    }
public:
    int minDistance(string word1, string word2) {
        s1=word1;
        s2=word2;
        dp.resize(s1.size(),vector<int> (s2.size(),-1));
        return f(0,0);

    }
};
