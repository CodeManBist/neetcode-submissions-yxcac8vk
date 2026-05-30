class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0, end = rows - 1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(target >= matrix[mid][0] && matrix[mid][cols - 1] >= target) {
                int left = 0, right = cols - 1;

                while(left <= right) {
                    int center = (left + right) / 2;

                    if(matrix[mid][center] == target) {
                        return true;
                    } else if(matrix[mid][center] < target) {
                        left = center + 1;
                    } else {
                        right = center - 1;
                    }
                }
                return false;
            }else if(target < matrix[mid][0]) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return false;
    }
};
