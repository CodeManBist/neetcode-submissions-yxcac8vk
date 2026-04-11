class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        int freq[26] = {0};


        for(char &task : tasks) {
            freq[task - 'A']++;
        }

        for(int count: freq) {
            if(count > 0) {
                pq.push(count);
            }
        }

        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;

            if(pq.empty()) {
                time = q.front().second;
            }else {
                int count = pq.top() - 1;
                pq.pop();
                if(count > 0) {
                    q.push({count, time+n});
                }
            }
            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};