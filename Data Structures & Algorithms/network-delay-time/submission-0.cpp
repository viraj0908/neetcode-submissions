class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int wt=it.second;
                int adjacent=it.first;
                if(dis+wt < dist[adjacent]){
                    dist[adjacent]=dis+wt;
                    pq.push({dist[adjacent],adjacent});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        if(ans==1e9) return -1;
        else return ans;
    }
};
