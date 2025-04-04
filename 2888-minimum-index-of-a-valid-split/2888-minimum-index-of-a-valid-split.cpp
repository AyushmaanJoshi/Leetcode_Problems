class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the dominant element using Boyer-Moore Majority Vote Algorithm
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Verify if candidate is dominant
        int total_count = count_if(nums.begin(), nums.end(), [&](int x) { return x == candidate; });
        if (total_count * 2 <= n) return -1;  // Not a dominant element

        // Step 3: Find the minimum valid split index
        int left_count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == candidate) left_count++;

            int right_count = total_count - left_count;
            if (left_count * 2 > (i + 1) && right_count * 2 > (n - i - 1)) {
                return i;
            }
        }

        return -1;  // No valid split found
    }
};
