class Solution {
    bool helper1(vector<int> &u,int x){
        return x > u[1];
    }
    bool helper2(vector<int> &v,int x){
        return x < v[0];
    }
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>& a,const vector<int> &b){
            return a[1]-a[0]+1 < b[1]-b[0]+1;
        });
        vector<int> output(queries.size());
        for(int i=0;i<queries.size();i++){
            int ans=-1;
            for(int j=0;j<intervals.size();j++){
                if(!helper1(intervals[j],queries[i]) && !helper2(intervals[j],queries[i])){
                    ans=intervals[j][1]-intervals[j][0]+1;
                    break;
                }
            }
            // if(ans==INT_MAX) output[i]=-1;
            output[i]=ans;
        }
        return output;
    }
};
