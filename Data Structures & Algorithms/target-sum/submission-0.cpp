class Solution {
    vector<vector<int>> dp;
    int offset=0;
    int f(vector<int> &nums,int ind,int sum,int target){
        if(ind==nums.size()){
            return sum==target;
        }
        if(dp[ind][sum+offset]!=-1) return dp[ind][sum+offset];
        return dp[ind][sum+offset]=f(nums,ind+1,sum+nums[ind],target)+f(nums,ind+1,sum-nums[ind],target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        dp.resize(nums.size(),vector<int>(2*total+2,-1));
        offset+=total;
        return f(nums,0,0,target);
    }
};
