class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int l=0,r=k-1;
        vector<int> res;
        for(int i=0;i<k;i++) pq.push({nums[i],i});
        while(r<nums.size()){
            while(pq.top().second<l) pq.pop();
            res.push_back(pq.top().first);
            r++;
            l++;
            pq.push({nums[r],r});
        }
        return res;
    }
};
