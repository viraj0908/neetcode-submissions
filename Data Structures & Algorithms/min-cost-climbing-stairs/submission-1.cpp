class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int one=0,two=0;
        for(int i=2;i<=n;i++){
            int ans=min(one+cost[i-2],two+cost[i-1]);
            one=two;
            two=ans;
        }
        return two;
    }
};
