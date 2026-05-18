class Solution {
    vector<vector<int>> res;
    vector<int> ans;
    void f(vector<int> &nums,vector<int> &ans,vector<int> &visited){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;
            ans.push_back(nums[i]);
            visited[i]=1;
            f(nums,ans,visited);
            visited[i]=0;
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(),0);
        f(nums,ans,visited);
        return res;
    }
};
