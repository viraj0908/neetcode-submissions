class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans(n+1);
        int cy=1;
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+cy;
            int d1=sum%10;
            int d2=sum/10;
            ans[i+1]=d1;
            if(d2) cy=1;
            else cy=0;
        }
        if(cy){
            ans[0]=1;
        }
        else{
            for(int i=1;i<=n;i++){
                ans[i-1]=ans[i];
            }
            ans.pop_back();
        }
        return ans;
        
    }
};
