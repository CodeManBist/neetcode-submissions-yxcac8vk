class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int> temp(3, 0);

        for(int i = 0; i < triplets.size(); i++) {

            if(triplets[i][0] > target[0] || 
               triplets[i][1] > target[1] ||
               triplets[i][2] > target[2] ) {
                continue;
               } else {
                temp[0] = max(temp[0], triplets[i][0]);
                temp[1] = max(temp[1], triplets[i][1]);
                temp[2] = max(temp[2], triplets[i][2]);
               }
        }
        if(temp[0] == target[0] && temp[1] == target[1] && temp[2] == target[2]) return true;

        return false;
    }
};
