class Solution {
    vector<vector<int>> res;
    vector<int> ans;
    void f(vector<int> &nums,vector<int> &ans,int ind,int target){
        if(target==0) {
            res.push_back(ans);
            return;
        }
        if(ind==nums.size() || nums[ind]>target) return;
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>target) break;
            ans.push_back(nums[i]);
            f(nums,ans,i+1,target-nums[i]);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,ans,0,target);
        return res;
    }
};
