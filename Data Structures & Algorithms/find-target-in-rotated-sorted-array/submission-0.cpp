class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]<=nums[r]){
                if(target<nums[l] || target>nums[r]) return -1;
            }
            int mid=l+(r-l)/2;
            if(nums[mid]>=nums[l]){
                if(nums[mid]==target) return mid;
                else if(target>nums[mid]) l=mid+1;
                else if(target<nums[mid] && target>=nums[l]) r=mid-1;
                else l=mid+1; 
            }
            else{
                if(nums[mid]==target) return mid;
                if(target>nums[mid] && target<=nums[r]) l=mid+1;
                else if(target<nums[mid] && target<nums[r]) r=mid-1;
                else r=mid-1;
            }
        }
        return -1;
    }
};
