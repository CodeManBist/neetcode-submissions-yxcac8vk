class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxVal = piles[0];
        for(int i = 1; i < piles.size(); i++) {
            if(piles[i] > maxVal) {
                maxVal = piles[i];
            }
        }
        return maxVal;
    }

    int calculateTotalHours(vector<int>& piles, int hourly) {
        int totalH = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalH += ceil((double) piles[i]/(double) hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while(low <= high) {
            int mid = (low + high) / 2;
            
            int totalH = calculateTotalHours(piles, mid);

            if(totalH <= h) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        return low;
    }
};
