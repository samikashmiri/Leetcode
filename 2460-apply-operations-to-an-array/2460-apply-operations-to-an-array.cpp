class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), index = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for (int num : nums) {
            if (num != 0) nums[index++] = num;
        }

        while (index < n) nums[index++] = 0;

        return nums;
    }
};
