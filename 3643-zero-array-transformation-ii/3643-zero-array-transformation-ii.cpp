class Solution {
public:
    bool canMakeZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end()); // Copy nums to avoid modifying original
        vector<int> lazy(n + 1, 0); // Lazy difference array

        // Apply the first k queries using the difference array
        for (int i = 0; i < k; i++) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            lazy[l] += val;
            lazy[r + 1] -= val;
        }

        // Apply the lazy array using prefix sum
        int current_decrement = 0;
        for (int i = 0; i < n; i++) {
            current_decrement += lazy[i]; // Accumulate decrement effect
            temp[i] = max(0, temp[i] - current_decrement); // Apply the decrement
        }

        // Check if the entire array is zero
        return all_of(temp.begin(), temp.end(), [](int x) { return x == 0; });
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0; // Already a Zero Array
        }

        int low = 0, high = queries.size(), answer = -1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (canMakeZero(nums, queries, mid)) {
                answer = mid;
                high = mid - 1; // Try to find a smaller k
            } else {
                low = mid + 1; // Need more queries
            }
        }

        return answer;
    }
};
