class Solution {
    int f(vector<int> &v){
        int x=v[0],y=v[1];
        return x*x+y*y;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> heap;
        for(int i=0;i<points.size();i++){
            int d=f(points[i]);
            heap.push({d,points[i]});
        }
        while(heap.size()>k){
            heap.pop();
        }
        vector<vector<int>> res;
        while(!heap.empty()){
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
