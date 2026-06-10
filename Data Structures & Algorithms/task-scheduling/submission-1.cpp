class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        priority_queue<int> pq;

        for(char task: tasks) {
            freq[task - 'A']++;
        }

        for(int f: freq) {
            if(f > 0) {
                pq.push(f);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()) {
                int curr = pq.top();
                pq.pop();
                
                if(curr - 1 > 0) {
                    q.push({ curr - 1, time + n + 1 });
                } 
            }
        
        }
        return time;
    }
};
