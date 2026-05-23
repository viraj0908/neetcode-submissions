class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int i=1,j=1;
        for(int k=2;k<=n;k++){
            int ans=i+j;
            i=j;
            j=ans;
        }  
        return j;
    }
};
