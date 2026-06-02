class Solution {
    bool overlap(vector<int> &u,vector<int> &v){
        return !(v[0]>=u[1] || v[1]<=u[0]);
    }
    vector<int> helper(vector<int> &u,vector<int> &v){
        if(v[1]<=u[1]) return v;
        else return u;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return 0;
        sort(intervals.begin(),intervals.end());
        vector<int> previous=intervals[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(!overlap(intervals[i],previous)){
                previous=intervals[i];
            }
            else{
                previous=helper(intervals[i],previous);
                ans++;
            }
        }
        return ans;
    }
};
