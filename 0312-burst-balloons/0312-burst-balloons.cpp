#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp; // Memoization table

    int burst(vector<int>& arr, int left, int right) {
        if (left > right) return 0; // Base case
        
        if (dp[left][right] != -1) return dp[left][right]; // Check if already computed

        int maxCoins = 0;

        for (int i = left; i <= right; i++) {
            int coins = arr[left - 1] * arr[i] * arr[right + 1]; 
            coins += burst(arr, left, i - 1) + burst(arr, i + 1, right); 

            maxCoins = max(maxCoins, coins);
        }

        return dp[left][right] = maxCoins; // Store result in dp table
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Add boundary balloons with value 1
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // Initialize DP table with -1 (uncomputed states)
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));

        return burst(arr, 1, n); // Start recursion
    }
};
