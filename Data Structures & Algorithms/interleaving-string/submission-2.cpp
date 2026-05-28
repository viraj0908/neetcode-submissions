class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<int> dp(s2.size()+1,0);
        dp[s2.size()]=1;
        for(int i=s2.size()-1;i>=0;i--){
            if(s2[i]==s3[s1.size()+i]) dp[i]=1;
            else dp[i]=0;
        }
        for(int i=s1.size()-1;i>=0;i--){
            vector<int> curr(s2.size()+1,0);
            for(int j=s2.size();j>=0;j--){
                if(s1[i]==s3[i+j]) curr[j]=curr[j] || dp[j];
                if(j<s2.size() && s2[j]==s3[i+j]) curr[j]=curr[j] || curr[j+1];
            }
            dp=curr;
        }
        return dp[0];
    }
};
