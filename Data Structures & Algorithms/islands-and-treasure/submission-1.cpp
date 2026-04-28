class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if(i - 1 >= 0 && grid[i-1][j] == INT_MAX) {
                grid[i-1][j] = grid[i][j] + 1;
                q.push(make_pair(i - 1, j));
            }

            if(i + 1 < n && grid[i+1][j] == INT_MAX) {
                grid[i+1][j] = grid[i][j] + 1;
                q.push(make_pair(i + 1, j));
            }

            if(j - 1 >= 0 && grid[i][j-1] == INT_MAX) {
                grid[i][j-1] = grid[i][j] + 1;
                q.push(make_pair(i, j-1));
            }
            if(j + 1 < m && grid[i][j+1] == INT_MAX) {
                grid[i][j+1] = grid[i][j] + 1;
                q.push(make_pair(i, j+1));
            }
        }
    }
};
