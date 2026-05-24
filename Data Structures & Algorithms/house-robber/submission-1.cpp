class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int one=0,two=nums[0];
        for(int i=2;i<=n;i++){
            int ans=max(nums[i-1]+one,two);
            one=two;
            two=ans;
        }
        return two;
    }
};
