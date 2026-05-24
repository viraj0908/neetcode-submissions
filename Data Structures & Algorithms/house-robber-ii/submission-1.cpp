class Solution {
    int helper(vector<int> v){
        if(v.size()==0) return 0;
        if(v.size()==1) return v[0];
        if(v.size()==2) return max(v[0],v[1]);

        int one=v[0],two=max(v[0],v[1]);
        for(int i=2;i<v.size();i++){
            int temp=max(v[i]+one,two);
            one=two;
            two=temp;
        } 
        return two;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(helper(vector<int>(nums.begin(),nums.end()-1)),helper(vector<int>(nums.begin()+1,nums.end())));
    }
};
