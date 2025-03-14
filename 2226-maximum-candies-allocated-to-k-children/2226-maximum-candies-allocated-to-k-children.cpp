class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 0, right = *max_element(candies.begin(), candies.end());

        while (left < right) {
            long long mid = (left + right + 1) / 2;
            long long count = 0;
            for (int candy : candies) count += candy / mid;

            if (count >= k) left = mid;  // Increase mid if we can satisfy k children
            else right = mid - 1;       // Decrease mid otherwise
        }

        return left;
    }
};
