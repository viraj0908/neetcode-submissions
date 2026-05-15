class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1,res=nums[0];
        while(l<=r){
            if(nums[l]<nums[r]) {
                res=min(res,nums[l]);
                break;
            }
            int mid=(l+r)/2;
            res=min(res,nums[mid]);
            if(nums[l]<=nums[mid]){
                l=mid+1;
            }
            else r=mid;
        }
        return res;
    }
};
