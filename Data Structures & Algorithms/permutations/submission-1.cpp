class Solution {
    vector<vector<int>> res;
    void f(vector<int> &nums,int ind){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            f(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,0);
        return res;
    }
};
