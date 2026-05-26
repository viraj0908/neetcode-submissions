class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmax=1,curmin=1;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i]*curmax;
            curmax=max(max(temp,nums[i]),nums[i]*curmin);
            curmin=min(min(temp,nums[i]),nums[i]*curmin);
            res=max(res,curmax);
        }
        return res;
    }
};
