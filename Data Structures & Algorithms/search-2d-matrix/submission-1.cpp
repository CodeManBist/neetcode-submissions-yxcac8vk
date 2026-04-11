class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0, bot = rows - 1;

        while(top <= bot) {
            int row = (top + bot) /2;
            if(target > matrix[row][cols - 1]) {
                top = row +  1;
            }else if(target < matrix[row][0]) {
                bot = row - 1;
            }else {
                top = row;
                break;
            }
        }

        if(!(top <= bot)) {
            return false;
        }
        
        int row = top;

        int l = 0, r = cols-1;
        while(l <= r) {
            int m = (l+r)/2;

            if(target == matrix[row][m]) {
                return true;
            }else if(target < matrix[row][m]) {
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return false;
    }
};
