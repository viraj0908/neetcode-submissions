class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    void f(vector<int> &nums,vector<int> &ans,int ind){
        if(ind==nums.size()){
            res.push_back(ans);
            return;
        }
        res.push_back(ans);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            f(nums,ans,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        f(nums,ans,0);
        return res;
    }
};
