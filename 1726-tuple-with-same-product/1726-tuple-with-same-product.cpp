class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size(), result = 0;

        // Count products of all pairs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Calculate the number of tuples for each product
        for (auto& [product, count] : productCount) {
            if (count > 1) {
                // Fix: Multiply by 8 as there are 8 permutations for each valid tuple
                result += 8 * (count * (count - 1)) / 2;
            }
        }

        return result;
    }
};
