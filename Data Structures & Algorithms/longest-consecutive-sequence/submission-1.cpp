class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        vector<int> arr;
        for(auto it:s){
            arr.push_back(it);
        }
        int ans=1,curr=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==1){
                curr+=1;
                ans=max(ans,curr);
            }
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        return ans;
    }
};
