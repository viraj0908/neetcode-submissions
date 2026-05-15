class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]+=1;
        }
        vector<vector<int>> ans(n+1);
        for(auto it:hash){
            int freq=it.second;
            int num=it.first;
            ans[freq].push_back(num);
        }
        int count=0;
        vector<int> res;
        for(int i=n;i>=0 && count<k;i--){
            if(ans[i].size()!=0){
                for(int j=0;j<ans[i].size() && count<k;j++){
                    res.push_back(ans[i][j]);
                    count++;
                }
            }
        }
        return res;

        
    }
};
