class Solution {
    vector<vector<int>> res;
    vector<int> ans;
    void f(vector<int> &nums,vector<int> &ans,int ind,int target){
        if(target==0){
            res.push_back(ans);
            return;
        }
        if(ind==nums.size()) return;
        if(nums[ind]>target) return;
        ans.push_back(nums[ind]);
        f(nums,ans,ind+1,target-nums[ind]);
        ans.pop_back();
        int i=ind+1;
        while(i<nums.size()){
            if(nums[i]!=nums[ind]) break;
            i++;
        }
        f(nums,ans,i,target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,ans,0,target);
        return res;
    }
};
