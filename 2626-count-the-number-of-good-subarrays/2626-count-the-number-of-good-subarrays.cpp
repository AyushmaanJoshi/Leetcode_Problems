class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long result = 0;
        long long pairCount = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Before incrementing frequency, count the additional pairs added
            pairCount += freq[nums[right]];
            freq[nums[right]]++;

            // Try to shrink window from the left while maintaining at least k pairs
            while (pairCount >= k) {
                result += nums.size() - right; // all subarrays from left to right are valid
                freq[nums[left]]--;
                pairCount -= freq[nums[left]]; // update pair count before reducing freq
                left++;
            }
        }

        return result;
    }
};
