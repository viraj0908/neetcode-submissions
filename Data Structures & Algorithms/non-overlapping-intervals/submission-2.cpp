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
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty()) {
                ans.push_back(intervals[i]);
            }
            else{
                vector<int> t1=ans.back();
                if(!overlap(t1,intervals[i])) ans.push_back(intervals[i]);
                else {
                    ans.pop_back();
                    ans.push_back(helper(t1,intervals[i]));
                }
            }
        }
        return n-ans.size();
    }
};
