class Solution {
    bool overlap(vector<int> &u,vector<int> &v){
        return !(v[0]>u[1] || v[1]<u[0]);
    }
    vector<int> merge(vector<int> &u,vector<int> &v){
        return  {min(u[0],v[0]),max(u[1],v[1])};
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
                continue;
            }
            else{
                vector<int> t1=ans.back();
                if(!overlap(t1,intervals[i])){
                    ans.push_back(intervals[i]);
                }
                else{
                    ans.pop_back();
                    ans.push_back(merge(intervals[i],t1));
                }
            }
        }
        return ans;
    }
};
