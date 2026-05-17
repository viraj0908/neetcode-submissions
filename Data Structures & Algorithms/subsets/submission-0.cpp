class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    void f(vector<int> &nums,int ind,vector<int> &subset){
        if(ind==nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        f(nums,ind+1,subset);
        subset.pop_back();
        f(nums,ind+1,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums,0,subset);
        return res;

    }
};
