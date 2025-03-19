class Solution {
public:

void  helper(vector<int> & arr, int pos){
    arr[pos]^=1;
    arr[pos+1]^=1;
    arr[pos+2]^=1;


}
    int minOperations(vector<int>& nums) {
        int count=0;
        for (int i=0;i<nums.size()-2;i++){
            if (nums[i]==1){
                continue;
            }
            helper(nums,i);
            count++;
        }

        if (nums[nums.size()-2]==0 || nums[nums.size()-1]==0){
            return -1;
        }
        return count;
    }
};