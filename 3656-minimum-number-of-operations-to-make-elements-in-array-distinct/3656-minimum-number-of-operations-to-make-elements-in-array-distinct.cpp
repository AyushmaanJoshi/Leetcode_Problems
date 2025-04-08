class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int min_ops = n / 3 + 1; // Maximum possible operations (safeguard upper bound)

        unordered_set<int> seen;
        // We start from the end and build up the set
        for (int i = n - 1; i >= 0; --i) {
            // Insert element into the set
            seen.insert(nums[i]);

            // Number of elements from i to end = n - i
            // If all these are unique
            if (seen.size() == n - i) {
                // How many operations needed to remove first i elements
                int ops = (i + 2) / 3;
                min_ops = min(min_ops, ops);
            }
        }

        return min_ops;
    }
};
