class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k1=nums[0];
        for(int i=1;i<nums.size();i++){
            k1=(k1^nums[i]);
        }
        int k=0;
        for(int i=1;i<=nums.size();i++) {
            k^=i;
        }
        return k^k1;
    }
};
