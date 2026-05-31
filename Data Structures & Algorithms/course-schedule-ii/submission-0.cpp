class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> indegree(n,0);
        for(auto node:adj){
            for(auto adjacent:node){
                indegree[adjacent]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjacent:adj[node]){
                indegree[adjacent]--;
                if(indegree[adjacent]==0) q.push(adjacent);
            }
        }
        if(ans.size()!=n) return {};
        else return ans;
    }
};
