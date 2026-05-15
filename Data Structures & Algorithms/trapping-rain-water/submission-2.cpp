class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0,ans=0;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<=rmax){
                if(lmax-height[l]>0) ans+=lmax-height[l];
                l++;
            }
            else{
                if(rmax-height[r]>0) ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};
