class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int current_and = 0, start = 0, max_length = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            
            while ((current_and & nums[end]) != 0) {
                current_and ^= nums[start];
                ++start;
            }
            current_and |= nums[end];
            max_length = max(max_length, end - start + 1);
        }
        
        return max_length;
    }
};
