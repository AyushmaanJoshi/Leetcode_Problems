class FenwickTree {
public:
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n = size + 2;
        bit.assign(n, 0);
    }

    void update(int index, int val) {
        index++;
        while (index < n) {
            bit[index] += val;
            index += index & -index;
        }
    }

    int query(int index) {
        index++;
        int res = 0;
        while (index > 0) {
            res += bit[index];
            index -= index & -index;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i;
        }

        // Map nums1[i] to its position in nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = pos2[nums1[i]];
        }

        vector<int> left(n), right(n);
        FenwickTree bit(n);

        // Calculate left count: how many elements before i have smaller mapped[i]
        for (int i = 0; i < n; ++i) {
            left[i] = bit.query(mapped[i] - 1);
            bit.update(mapped[i], 1);
        }

        // Reset Fenwick Tree to reuse for right count
        bit = FenwickTree(n);

        // Calculate right count: how many elements after i have larger mapped[i]
        for (int i = n - 1; i >= 0; --i) {
            right[i] = bit.query(n - 1) - bit.query(mapped[i]);
            bit.update(mapped[i], 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * left[i] * right[i];
        }

        return ans;
    }
};
