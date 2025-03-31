class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // Only one partition means min = max score.

        vector<long long> pairs;
        
        // Step 1: Calculate pair sums (weights[i] + weights[i+1])
        for (int i = 0; i < n - 1; i++) {
            pairs.push_back(weights[i] + weights[i + 1]);
        }
        
        // Step 2: Sort the pairs array
        sort(pairs.begin(), pairs.end());

        long long minScore = 0, maxScore = 0;

        // Step 3: Compute the difference between max and min scores
        for (int i = 0; i < k - 1; i++) {
            minScore += pairs[i];                        // Smallest (k-1) sums
            maxScore += pairs[n - 2 - i];               // Largest (k-1) sums
        }

        return maxScore - minScore;
    }
};
