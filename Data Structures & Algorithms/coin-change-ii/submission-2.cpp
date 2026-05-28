class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        dp[amount]=1;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(amount+1,0);
            for(int j=amount;j>=0;j--){
                curr[j]=dp[j];
                if(coins[i]+j<=amount) curr[j]+=curr[j+coins[i]];
            }
            dp=curr;
        }
        return dp[0];
    }
};
