class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++) {
            int distSq = points[i][0] *  points[i][0] + points[i][1] * points[i][1];
            pq.push({distSq, i});

            if(pq.size() > k) {
                pq.pop();
            }
        } 

        while(!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
