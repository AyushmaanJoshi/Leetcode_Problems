class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        for (int c : candies) total += c;
        if (total < k) return 0; // Not enough candies for each child to get at least 1.

        int low = 1, high = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long count = 0;

            for (int c : candies) {
                count += c / mid; // Number of children that can get 'mid' candies from this pile
            }

            if (count >= k) {
                result = mid;  // Valid solution, try for a higher value
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
