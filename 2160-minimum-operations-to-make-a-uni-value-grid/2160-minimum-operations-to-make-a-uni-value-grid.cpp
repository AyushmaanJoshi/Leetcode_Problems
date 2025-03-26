class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();

        // Flatten the grid into a 1D array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // Check divisibility condition
        int remainder = nums[0] % x;
        for (int num : nums) {
            if (num % x != remainder) return -1; // Not possible
        }

        // Find the median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        // Compute operations needed
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
