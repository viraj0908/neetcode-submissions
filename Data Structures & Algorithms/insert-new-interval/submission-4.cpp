class Solution {
    vector<int> merge(vector<int> u,vector<int> v){
        vector<int> res(2);
        res[0]=min(u[0],v[0]);
        res[1]=max(u[1],v[1]);
        return res;
    }


    bool overlap(vector<int> &u,vector<int> &v){
        if((v[1]>u[0] && v[0]>u[1]) || (v[1]<u[0] && v[0]<u[0])) return false;
        else return true;
    }

    bool f(vector<int> &u,vector<int> &v){
        return u[1]>v[1] && u[0]>v[1];
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool inserted=false;
        if(intervals.size()==0) {
            ans.push_back(newInterval);
            return ans;
        }
        if(newInterval[1]<intervals[0][0])  {
            ans.push_back(newInterval);
            inserted=true;
        }
        
        for(int i=0;i<intervals.size();i++){
            if(!overlap(intervals[i],newInterval)){
                if(inserted) ans.push_back(intervals[i]);
                else{
                    if(f(intervals[i],newInterval)){
                        ans.push_back(newInterval);
                        ans.push_back(intervals[i]);
                        inserted=true;
                    }
                    else {
                        ans.push_back(intervals[i]);
                    }
                }
            }
            else{
                vector<int> temp=newInterval;
                while(i < intervals.size() && overlap(intervals[i],temp)){
                    temp=merge(intervals[i],temp);
                    i++;
                }
                i--;
                ans.push_back(temp);
                inserted=true;
            }
        }
        if(newInterval[0] > intervals[intervals.size()-1][1]) ans.push_back(newInterval);
        return ans;
    }
};
