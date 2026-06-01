class Solution {
    vector<vector<int>> adj;
    vector<int> visited;
    unordered_set<int> cycle;
    int start;

    bool dfs(int node,int prev){
        if(visited[node]) {
            start=node;
            return true;
        }
        visited[node]=1;
        for(auto adjacent:adj[node]){
            if(adjacent==prev) continue;
            if(dfs(adjacent,node)){
                if(start!=-1) cycle.insert(node);
                if(node==start) start=-1;
                return true;
            }
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        adj.resize(n+1);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        visited.resize(n+1,0);
        start=-1;
        dfs(1,-1);
        for(int i=n-1;i>=0;i--){
            int u=edges[i][0];
            int v=edges[i][1];
            if(cycle.count(u) && cycle.count(v)) return {u,v};
        }
        return {};
    }
};
