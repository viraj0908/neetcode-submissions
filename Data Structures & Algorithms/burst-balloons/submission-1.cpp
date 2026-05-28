class Solution {
    vector<int> arr;
    vector<vector<int>> dp;
    int f(int l,int r){
        if(l>r || r<l) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l;i<=r;i++){
            ans=max(ans,(arr[l-1]*arr[i]*arr[r+1])+f(i+1,r)+f(l,i-1));
        }
        return dp[l][r]= ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        arr.resize(nums.size()+2);
        arr[0]=1;
        for(int i=0;i<nums.size();i++){
            arr[i+1]=nums[i];
        }
        arr[nums.size()+1]=1;
        dp.resize(nums.size()+1,vector<int> (nums.size()+1,-1));
        return f(1,nums.size());
    }
};
