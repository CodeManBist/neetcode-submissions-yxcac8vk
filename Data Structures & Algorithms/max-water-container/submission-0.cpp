class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int totalArea = 0;
        while(left < right) {
            int currArea = min(heights[left], heights[right]) * (right - left);
            totalArea = max(totalArea, currArea); 
            if(heights[left] < heights[right]) {
                left++;
            }else {
                right--;
            } 
        }
        return  totalArea;
    }
};
