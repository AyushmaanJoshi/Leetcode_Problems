class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1}; // No primes exist below 2

        // Step 1: Use the Sieve of Eratosthenes to precompute primes
        int limit = right + 1;
        vector<bool> is_prime(limit, true);
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i < limit; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < limit; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // Step 2: Find closest primes in the given range
        int prev_prime = -1, min_gap = INT_MAX;
        vector<int> res{-1, -1};

        for (int i = left; i <= right; i++) {
            if (is_prime[i]) {
                if (prev_prime != -1 && (i - prev_prime) < min_gap) {
                    min_gap = i - prev_prime;
                    res = {prev_prime, i};
                }
                prev_prime = i;
            }
        }

        return res;
    }
};
