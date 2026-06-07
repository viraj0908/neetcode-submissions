class Solution {
public:
    int getSum(int a, int b) {
        int res=0;
        int cy=0;
        for(int i=0;i<32;i++){
            int d1=(a>>i) & 1;
            int d2=(b>>i) & 1;
            int d= (d1 ^ d2 ^ cy);
            if(d) res =(res | (1<<i));
            if((d1 & d2) || (d1 & cy) || (d2 & cy)) cy=1;
            else cy=0;
        }
        return res;
    }
};
