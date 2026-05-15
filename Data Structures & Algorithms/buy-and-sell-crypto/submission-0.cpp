class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> rmax(n);
        rmax[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]>=rmax[i+1]) rmax[i]=prices[i];
            else rmax[i]=rmax[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(rmax[i]-prices[i]>=0) ans=max(ans,rmax[i]-prices[i]);
        }
        
        return ans;
    }
};
