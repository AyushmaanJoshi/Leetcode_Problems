class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // If any element is less than k, return -1
        for (int num : nums) {
            if (num < k) return -1;
        }

        set<int> uniqueNums;
        for (int num : nums) {
            if (num > k) uniqueNums.insert(num);
        }

        vector<int> vals(uniqueNums.begin(), uniqueNums.end());
        sort(vals.rbegin(), vals.rend()); // Descending order

        int ops = 0;
        int n = nums.size();
        vector<int> curr = nums;

        for (int i = 0; i < vals.size(); ++i) {
            int h = (i + 1 < vals.size()) ? vals[i + 1] : k;

            // Check if all elements greater than h are equal
            int greater = -1;
            bool valid = true;
            for (int x : curr) {
                if (x > h) {
                    if (greater == -1) greater = x;
                    else if (x != greater) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            // Perform operation: set all > h to h
            for (int j = 0; j < n; ++j) {
                if (curr[j] > h) {
                    curr[j] = h;
                }
            }
            ++ops;
            if (*max_element(curr.begin(), curr.end()) == k) return ops;
        }

        return (*max_element(curr.begin(), curr.end()) == k) ? ops : -1;
    }
};
