class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size()+2);
        arr[0]=1;
        for(int i=0;i<nums.size();i++) arr[i+1]=nums[i];
        arr[nums.size()+1]=1;
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));
        for(int i=nums.size();i>=1;i--){
            for(int j=i;j<=nums.size();j++){
                if(j<i) continue;
                for(int k=i;k<=j;k++){
                    dp[i][j]=max(dp[i][j],(arr[i-1]*arr[k]*arr[j+1])+dp[k+1][j]+dp[i][k-1]);
                }
            }
        }
        return dp[1][nums.size()];
    }
};
