class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n),b(n),res(n);
        a[0]=nums[0];
        for(int i=1;i<n;i++){
            a[i]=a[i-1]*nums[i];
        }
        b[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            b[i]=b[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                res[i]=b[1];
            }
            else if(i==n-1) res[i]=a[n-2];
            else {
                res[i]=a[i-1]*b[i+1];
            }
        }
        return res;
    }
};
