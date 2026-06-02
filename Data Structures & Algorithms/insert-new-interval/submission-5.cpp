class Solution {
    bool overlap(vector<int> &u,vector<int> &v){
        return !(v[0]>u[1] || v[1]<u[0]);
    }

    bool helper(vector<int> &u,vector<int> &v){
        return v[0]>u[1];
    }

    vector<int> merge(vector<int> &u,vector<int> &v){
        vector<int> res(2);
        res[0]=min(u[0],v[0]);
        res[1]=max(u[1],v[1]);
        return res;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0) {
            ans.push_back(newInterval);
            return ans;
        }
        int i=0;
        while(i<n && helper(intervals[i],newInterval)){
            ans.push_back(intervals[i]);
            i++;
        }
        vector<int> temp=newInterval;
        while(i<n && overlap(intervals[i],temp)){
            temp=merge(intervals[i],temp);
            i++;
        }
        ans.push_back(temp);
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        // if(newInterval[0]>intervals[n-1][1]) ans.push_back(newInterval);
        return ans;
        
    }
};
