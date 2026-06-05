class Solution {
    vector<string> path;
    int totalTickets;

    bool dfs(
        string curr,
        unordered_map<string, map<string,int>>& adj
    ) {
        if(path.size() == totalTickets + 1)
            return true;

        for(auto &[next, cnt] : adj[curr]) {

            if(cnt == 0) continue;

            cnt--;                    // use ticket
            path.push_back(next);

            if(dfs(next, adj))
                return true;

            path.pop_back();          // backtrack
            cnt++;                    // restore ticket
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, map<string,int>> adj;

        for(auto &t : tickets)
            adj[t[0]][t[1]]++;

        totalTickets = tickets.size();

        path.push_back("JFK");

        dfs("JFK", adj);

        return path;
    }
};