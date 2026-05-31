class Solution {
    bool dfs(vector<vector<int>> &adj,int node,vector<int> &visited,int parent){
        visited[node]=1;
        for(auto adjacent:adj[node]){
            if(adjacent!=parent && visited[adjacent]) return false;
            else if(!visited[adjacent]) {
                if(!dfs(adj,adjacent,visited,node)) return false;
            }
        }
        return true;

    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
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
                if(!dfs(adj,i,visited,-1)) return false;
                components++;
            }
        }
        if(components>1) return false;
        return true;
        
    }
};
