class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       int n = hand.size();

       if(n % groupSize != 0) return false;
       
       sort(hand.begin(), hand.end());

       unordered_map<int, int> freq;

       for(int x : hand) {
        freq[x]++;
       }

       for(int i = 0; i < n; i++) {
        int x = hand[i];

        if(freq[x] == 0) continue;

        for(int j = 0; j < groupSize; j++) {
            if(freq[x + j] == 0) return false;
            freq[x + j]--;
        }
       }

       return true;
    }
};
