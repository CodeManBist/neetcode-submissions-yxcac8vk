class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int end = 0;

        for(int pile: piles) {
            end = max(end, pile);
        }

        int ans = end;

        while(st <= end) {
            int mid = (st + end) / 2;
            int totalHours = 0;

            for(int num: piles) {
                totalHours += (num + mid - 1) / mid;
            }

            if(totalHours <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};
