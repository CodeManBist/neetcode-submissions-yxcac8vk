class Solution {
public:
    bool isCycle(vector<bool>& vis, vector<bool>& rec, int src, vector<vector<int>>& graph) {
        vis[src] = true;
        rec[src] = true;

        for(int i = 0; i < graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];

            if(src == u) {
                if(!vis[v]) {
                    if (isCycle(vis, rec, v, graph)) {
                        return true;
                    }
                }else if(rec[v]) {
                    return true;
                }
            }
        }
        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycle(vis, rec, i, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
