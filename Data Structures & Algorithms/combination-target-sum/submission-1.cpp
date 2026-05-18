class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    void f(vector<int> &nums,int ind,vector<int> &ans,int target){
        if(target==0) {
            res.push_back(ans);
            return;
        }
        if(ind==nums.size()){
            return;
        }
        if(nums[ind]>target) {
            f(nums,ind+1,ans,target);
            return ;
        }
        ans.push_back(nums[ind]);
        f(nums,ind,ans,target-nums[ind]);
        ans.pop_back();
        f(nums,ind+1,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        f(nums,0,ans,target);
        return res;
    }
};
