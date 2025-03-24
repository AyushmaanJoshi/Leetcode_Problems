#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int occupiedDays = 0;
        int prevStart = -1, prevEnd = -1;

        // Step 2: Merge overlapping intervals
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            if (start > prevEnd) { // No overlap, count previous interval
                if (prevEnd != -1) occupiedDays += (prevEnd - prevStart + 1);
                prevStart = start;
                prevEnd = end;
            } else { // Overlapping, merge intervals
                prevEnd = max(prevEnd, end);
            }
        }

        // Add the last merged interval
        occupiedDays += (prevEnd - prevStart + 1);

        // Step 3: Compute available days
        return days - occupiedDays;
    }
};