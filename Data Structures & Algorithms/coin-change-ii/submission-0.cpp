class Solution {
    vector<vector<int>> dp;
    int f(vector<int>& coins,int ind, int amount,int target){
        if(amount==target) return 1;
        if(amount > target) return 0;
        if(ind==coins.size()) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        return dp[ind][amount]=f(coins,ind,amount+coins[ind],target)+f(coins,ind+1,amount,target);

    }
public:
    int change(int amount, vector<int>& coins) {    
        dp.resize(coins.size(),vector<int>(amount+1,-1));
        return f(coins,0,0,amount);

    }
};
