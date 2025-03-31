class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
        vector<int> result;
        
        // Step 1: Store the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Step 2: Iterate to find partitions
        int start = 0, maxEnd = 0;
        for (int i = 0; i < s.length(); i++) {
            maxEnd = max(maxEnd, lastIndex[s[i] - 'a']);  // Update maxEnd
            
            // If we reached the farthest index of any character seen, it's a partition
            if (i == maxEnd) {
                result.push_back(i - start + 1);
                start = i + 1;  // Start a new partition
            }
        }
        
        return result;
    }
};
