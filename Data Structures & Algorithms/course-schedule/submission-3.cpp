class Solution {
    int n;
    bool dfs(vector<vector<int>> &adj,int node,vector<int> &visited){
        visited[node]=1;
        for(auto adjacent:adj[node]){
            if(visited[adjacent]==1) return false;
            if(visited[adjacent]==0 && !dfs(adj,adjacent,visited)) return false;
        }
        visited[node]=2;
        return true;
    }



public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        // queue<int> q;
        // vector<int> visited(n,0);

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
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
            for(auto adjacent:adj[node]){
                indegree[adjacent]--;
                if(indegree[adjacent]==0) {
                    // visited[adjacent]=1;
                    q.push(adjacent);
                }
            }
        }
        return finish==n;
    }
};
