class Solution {
    int f(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=(d*d);
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=f(n);
        while(slow!=fast){
            slow=f(slow);
            fast=f(fast);
            fast=f(fast);
        }
        return fast==1;
    }
};
