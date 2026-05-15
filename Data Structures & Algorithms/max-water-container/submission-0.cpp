class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int ans=(n-1)*min(heights[0],heights[n-1]);
        int l=0,r=n-1;
        while(l<r){
            ans=max(ans,(r-l)*min(heights[l],heights[r]));

            if(heights[l]<=heights[r]){
                int lh=heights[l];
                while(heights[l]<=lh) l++;
            }
            else{
                int rh=heights[r];
                while(heights[r]<=rh) r--;
            }
        }
        return ans;
    }
};
