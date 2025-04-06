class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }

private:
    int helper(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()) {
            return currentXOR;
        }

        // Two choices: include nums[index] or not
        int include = helper(nums, index + 1, currentXOR ^ nums[index]);
        int exclude = helper(nums, index + 1, currentXOR);

        return include + exclude;
    }
};
