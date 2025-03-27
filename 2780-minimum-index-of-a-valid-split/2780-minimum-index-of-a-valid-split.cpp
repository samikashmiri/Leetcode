class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size(), dominant = -1, count = 0;

        // Find the dominant element
        for (int num : nums) {
            if (count == 0) dominant = num;
            count += (num == dominant) ? 1 : -1;
        }

        // Count occurrences of the dominant element
        count = 0;
        for (int num : nums) {
            if (num == dominant) count++;
        }
        if (count * 2 <= n) return -1;

        // Find the minimum valid split
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominant) leftCount++;
            if (leftCount * 2 > i + 1 && (count - leftCount) * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};
