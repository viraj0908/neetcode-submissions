class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> dp(m+1);
        for(int i=0;i<=m;i++) dp[i]=m-i;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(m+1);
            for(int j=m;j>=0;j--){
                if(j==m) {
                    curr[j]=n-i;
                    continue;
                }
                if(word1[i]==word2[j]) curr[j]=dp[j+1];
                else curr[j]=1+min(dp[j],min(dp[j+1],curr[j+1]));
            }
            dp=curr;
        }
        return dp[0];
    }
};
