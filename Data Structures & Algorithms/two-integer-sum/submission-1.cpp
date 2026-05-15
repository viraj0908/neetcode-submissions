class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> ans={};
        for(int i=0;i<nums.size();i++){
            if(hash.count(target-nums[i])){
                return ans={hash[target-nums[i]],i};
            }
            else {
                hash[nums[i]]=i;
            }
        }
        
    }
};
