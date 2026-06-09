class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> temp;

        for(int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int distance = (x*x) + (y*y);
            temp.push_back({ distance, i });
        }

        sort(temp.begin(), temp.end());

        for(int i = 0; i < k; i++) {
            ans.push_back(points[temp[i].second]);
        }

        return ans;
    }
};
