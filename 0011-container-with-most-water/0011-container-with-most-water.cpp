class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                // Pointer at the beginning
        int right = height.size() - 1; // Pointer at the end
        int max_area = 0;            // Variable to store the maximum area

        while (left < right) {
            // Calculate the area for the current container
            int width = right - left;
            int current_area = width * min(height[left], height[right]);
            max_area = max(max_area, current_area);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
