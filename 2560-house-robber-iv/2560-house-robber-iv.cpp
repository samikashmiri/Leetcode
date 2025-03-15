class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0, prevRobbed = -2;

            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= mid && i > prevRobbed + 1) {
                    count++;
                    prevRobbed = i;
                }
            }

            if (count >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
