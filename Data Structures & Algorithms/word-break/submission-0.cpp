class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<wordDict.size();j++){
                string str=wordDict[j];
                dp[i]= (i+str.size()<=n) && (s.substr(i,str.size())==str) && dp[i+str.size()];
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
