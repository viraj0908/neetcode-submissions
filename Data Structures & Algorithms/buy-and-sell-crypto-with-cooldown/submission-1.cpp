class Solution {
    vector<vector<int>> dp;
    int f(vector<int> &prices,int ind,int buying){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buying]!=-1) return dp[ind][buying];
        if(buying){
            return dp[ind][buying]=max(-prices[ind]+f(prices,ind+1,0),f(prices,ind+1,1));
        }
        else{
            return dp[ind][0]=max(prices[ind]+f(prices,ind+2,1),f(prices,ind+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int> (2,-1));
        return f(prices,0,1);
    }
};
