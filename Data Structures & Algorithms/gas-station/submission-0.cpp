class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int gasSum = 0;
        int costSum = 0;

        for(int i = 0; i< n; i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }

        if(gasSum < costSum) return -1;

        int res = 0;
        int total = 0;

        for(int i = 0; i < n; i++) {

            total += gas[i] - cost[i];

            if(total < 0) {
                res = i + 1;
                total = 0;
            }
        }

        return res;
    }
};
