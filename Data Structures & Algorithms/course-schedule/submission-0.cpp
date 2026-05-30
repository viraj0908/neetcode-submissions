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
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(!dfs(adj,i,visited)) return false; 
            }
        }
        return true;
    }
};
