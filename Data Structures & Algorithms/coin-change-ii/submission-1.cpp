class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1));
        int n=coins.size();
        for(int i=0;i<=coins.size();i++){
            dp[i][amount]=1;
        }
        for(int i=0;i<amount;i++){
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=amount-1;j>=0;j--){
                dp[i][j]=dp[i+1][j];
                if(coins[i]+j<=amount) dp[i][j]+=dp[i][j+coins[i]];
            }
        }
        return dp[0][0];
    }
};
