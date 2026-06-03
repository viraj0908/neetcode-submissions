class Solution {
    bool helper1(vector<int> &u,int x){
        return (x > u[1]);
    }
    bool helper2(vector<int> &u,int x){
        return (x < u[0]);
    }
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<int> output(queries.size());
        for(int i=0;i<queries.size();i++){
            int ans=INT_MAX;
            for(int j=0;j<intervals.size();j++){
                if(helper1(intervals[j],queries[i])) continue;
                else if(helper2(intervals[j],queries[i])) break;
                else{
                    ans=min(ans,intervals[j][1]-intervals[j][0]+1);
                }
            }
            if(ans==INT_MAX) output[i]=-1;
            else output[i]=ans;
        }
        return output;
    }
};
