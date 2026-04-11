class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;

        int lMax = height[0], rMax = height[n-1];
        int currArea = 0, maxArea = 0;

        while(left < right) {
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            if(lMax < rMax) {
                currArea = lMax - height[left];
                left++;
            }else {
                currArea = rMax - height[right];
                right--;
            }
            maxArea += currArea;
        }
        return maxArea;
    }
};
