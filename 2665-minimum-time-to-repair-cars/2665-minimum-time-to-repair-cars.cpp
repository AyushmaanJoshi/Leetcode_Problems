class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long t) {
        long long repairedCars = 0;
        for (int r : ranks) {
            repairedCars += sqrt(t / r);
            if (repairedCars >= cars) return true;  // Early exit if we reach the required cars
        }
        return repairedCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long) (*min_element(ranks.begin(), ranks.end())) * (long long) cars * (long long) cars;
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;  // Update answer
                right = mid - 1;  // Try a smaller time
            } else {
                left = mid + 1;  // Increase time
            }
        }
        return ans;
    }
};
