class Solution {
    void dfs(vector<vector<int>> &adj,int node,vector<int> &visited){
        visited[node]=1;
        for(auto adjacent:adj[node]){
            if(!visited[adjacent]) dfs(adj,adjacent,visited);
        }
        return ;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);    
        }
        vector<int> visited(n,0);
        int components=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                components++;
            }
        }
        return components;

    }
};
