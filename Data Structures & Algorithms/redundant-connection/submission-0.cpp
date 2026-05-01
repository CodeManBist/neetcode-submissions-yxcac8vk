class Solution {
public:
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<bool>& vis) {
        if(src == target) {
            return true;
        }

        vis[src] = true;

        for(int neighbor: adj[src]) {
            if(!vis[neighbor]) {
                if(dfs(neighbor, target, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<vector<int>> adj(n+1);

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> vis(n + 1, false);

            if(!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, vis)) {
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
