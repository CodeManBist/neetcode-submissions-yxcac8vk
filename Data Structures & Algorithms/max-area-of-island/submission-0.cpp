class Solution {
public:
    int dfs(int i, int j,  vector<vector<bool>>& vis, int length, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j]) {
            return length;
        }
        
        vis[i][j] = true;
        length++;

        length = dfs(i+1, j, vis, length, grid);
        length = dfs(i-1, j, vis, length, grid);
        length = dfs(i, j+1, vis, length, grid);
        length = dfs(i, j-1, vis, length, grid);
        
        return length;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    int length = 0;
                    length = dfs(i, j, vis, length, grid);
                    maxLength = max(maxLength, length);
                }
            }
        }
        return maxLength;
    }
};
