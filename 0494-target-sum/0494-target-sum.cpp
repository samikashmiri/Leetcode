class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return dfs(nums, target, 0, 0, memo);
    }
    
private:
    int dfs(vector<int>& nums, int target, int index, int currentSum, unordered_map<string, int>& memo) {
        if (index == nums.size()) {
            return currentSum == target ? 1 : 0;
        }
        
        string key = to_string(index) + "," + to_string(currentSum);
        if (memo.count(key)) {
            return memo[key];
        }
        
        int add = dfs(nums, target, index + 1, currentSum + nums[index], memo);
        int subtract = dfs(nums, target, index + 1, currentSum - nums[index], memo);
        
        memo[key] = add + subtract;
        return memo[key];
    }
};
