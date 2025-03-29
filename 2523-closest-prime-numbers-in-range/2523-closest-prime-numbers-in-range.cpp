class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) {
            return {-1, -1};
        }

        // Sieve of Eratosthenes to find primes up to right
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= right; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= right; j += i) {
                    sieve[j] = false;
                }
            }
        }

        // Collect primes within the [left, right] range
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (sieve[i]) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }

        // Find the pair with the smallest difference
        int min_diff = INT_MAX;
        vector<int> result = {-1, -1};
        for (int i = 0; i < primes.size() - 1; ++i) {
            int diff = primes[i+1] - primes[i];
            if (diff < min_diff) {
                min_diff = diff;
                result = {primes[i], primes[i+1]};
            }
        }

        return result;
    }
};