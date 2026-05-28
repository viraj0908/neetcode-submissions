class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int offset=total;
        vector<vector<int>> dp(nums.size()+1,vector<int> (2*total+2));
        for(int i=0;i<2*total+2;i++){
            if(i==target+offset) dp[n][i]=1;
            else dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=(2*total+1);j>=0;j--){
                dp[i][j]=0;
                if(j-nums[i]>=0) dp[i][j]+=dp[i+1][j-nums[i]];
                if(j+nums[i]<(2*total+2)) dp[i][j]+=dp[i+1][j+nums[i]];
            }
        }
        return dp[0][offset];
    }
};
