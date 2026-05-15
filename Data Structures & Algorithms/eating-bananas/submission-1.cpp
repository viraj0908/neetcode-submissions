class Solution {
    bool predicate(int mid,vector<int> piles,int h){
        int t=0;
        for(int i=0;i<piles.size();i++){
            t+=(ceil((double)piles[i]/mid));
        }
        return (t<=h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int kmax=*max_element(piles.begin(),piles.end());
        int l=1,r=kmax;
        while((r-l)>1){
            int mid=l+(r-l)/2;
            if(predicate(mid,piles,h)){
                r=mid;
            }
            else l=mid+1;
        }
        if(predicate(l,piles,h)) return l;
        else return r;
    }
};
