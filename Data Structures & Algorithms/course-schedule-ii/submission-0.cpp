class Solution {
public:
    bool isCycle(int src, vector<bool>& vis, vector<bool>& rec ,vector<vector<int>>& prerequisites) {
        vis[src] = true;
        rec[src] = true;
        
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(src == u) {
                if(!vis[v]) {
                if(isCycle(v, vis, rec, prerequisites)) {
                    return true;
                }
            } else if(rec[v]) {
                return true;
            }
            }
        }
        rec[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool>& vis2, stack<int>& s, vector<vector<int>>& prerequisites) {
        vis2[src] = true;

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src) {
                if(!vis2[v]) {
                topoSort(v, vis2, s, prerequisites);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> ans;
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for(int i = 0 ; i < V; i++) {
            if(!vis[i]) {
                if(isCycle(i, vis, rec, prerequisites)) {
                    return ans;
                }
            }
        }
        
        vector<bool> vis2(V, false);
        stack<int> s;

        for(int i = 0; i < V; i++) {
            if(!vis2[i]) {
                topoSort(i, vis2, s, prerequisites);
            }
        }
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
