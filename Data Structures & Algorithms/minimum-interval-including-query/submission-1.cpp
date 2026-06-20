class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        int ptr = 0;

        // reuse queries as answer array
        fill(queries.begin(), queries.end(), -1);

        for(auto &[query, idx] : q) {

            while(ptr < intervals.size() &&
                  intervals[ptr][0] <= query) {

                int start = intervals[ptr][0];
                int end   = intervals[ptr][1];

                minHeap.push({end - start + 1, end});
                ptr++;
            }

            while(!minHeap.empty() &&
                  minHeap.top().second < query) {
                minHeap.pop();
            }

            if(!minHeap.empty()) {
                queries[idx] = minHeap.top().first;
            }
        }

        return queries;
    }
};