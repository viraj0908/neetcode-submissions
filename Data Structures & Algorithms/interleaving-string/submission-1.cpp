class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                if(i==s1.size() && j==s2.size()) {
                    dp[s1.size()][s2.size()]=1;
                    continue;
                }
                if(i<s1.size() && i+j<s1.size() + s2.size() && s1[i]==s3[i+j] ) dp[i][j]=dp[i][j] || dp[i+1][j];
                if(j<s2.size() && i+j <s1.size() +s2.size() && s2[j]==s3[i+j]) dp[i][j]=dp[i][j] || dp[i][j+1]; 
            }
        }
        return dp[0][0];
    }
};
