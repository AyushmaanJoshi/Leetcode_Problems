#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // DP array to store max points from index i

        for (int i = n - 1; i >= 0; --i) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            int nextQuestion = i + brainpower + 1;

            // Solve the question
            long long solve = points + (nextQuestion < n ? dp[nextQuestion] : 0);

            // Skip the question
            long long skip = dp[i + 1];

            // Take the maximum of both choices
            dp[i] = max(solve, skip);
        }

        return dp[0]; // Maximum points starting from question 0
    }
};

