class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1); // Stores last seen index of 'a', 'b', 'c'
        int count = 0;
        int n = s.length();
        
        for (int right = 0; right < n; right++) {
            lastSeen[s[right] - 'a'] = right;  // Update last index of current character
            
            // The minimum index among last seen positions of 'a', 'b', and 'c'
            int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
            
            // If all three characters are found at least once, count substrings
            if (minIndex != -1) {
                count += minIndex + 1; 
            }
        }
        
        return count;
    }
};
