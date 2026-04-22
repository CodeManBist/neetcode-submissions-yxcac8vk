class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <m; j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                if(x + 1 < n && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    q.push(make_pair(x+1, y));
                    fresh--;
                }

                if(x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    q.push(make_pair(x-1, y));
                    fresh--;
                }
                if(y+ 1 < m && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    q.push(make_pair(x, y+1));
                    fresh--;
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    q.push(make_pair(x, y-1));
                    fresh--;
                }
            } 

            if(!q.empty()) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
