class Solution {
    int f(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            n=n/10;
            sum+=(d*d);
        }
        return sum;
    }
    int helper(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int x=n;
        map<int,int> hash;
        while(1){
            if(hash.count(x)) break;
            hash[x]=1;
            x=f(x);
            cout<<x<<endl;
            if(helper(x)==1) return true;           
        }
        return false;
        
    }
};
