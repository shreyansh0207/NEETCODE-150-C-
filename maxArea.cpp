class Solution {
public:
    int maxArea(vector<int>& height) {
        int left  = 0;
        int right = height.size() - 1;
        int i; int maximumWater = 0;
        while (left < right){
            int width = right - left;
            int minHeight = min(height[left] , height[right]);
            int currentWater = width * minHeight;
        

        maximumWater = max (maximumWater ,currentWater);

        if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            } }
             return maximumWater;
        
       

    }
};