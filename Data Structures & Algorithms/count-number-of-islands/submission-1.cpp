class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({ r, c });
        vis[r][c] = true;

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == '1' && !vis[ni][nj]) {
                    vis[ni][nj] = true;
                    q.push({ ni, nj });
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    ans += 1;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};