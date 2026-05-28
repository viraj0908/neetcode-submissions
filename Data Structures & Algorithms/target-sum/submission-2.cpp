class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        int size=2*total+2;
        vector<int> dp(size,0);
        int offset=total;
        dp[target+offset]=1;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(size);
            for(int j=size-1;j>=0;j--){
                curr[j]=0;
                if(j-nums[i]>=0) curr[j]+=dp[j-nums[i]];
                if(j+nums[i]<size) curr[j]+=dp[j+nums[i]];
            }
            dp=curr;
        }
        return dp[offset];
    }
};
