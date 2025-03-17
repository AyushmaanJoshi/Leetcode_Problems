class Solution {
public:
    bool divideArray(vector<int>& nums) {
     
        if(nums.size()%2!=0){
            return false;
        }

        unordered_map<int,int> mpp;

        for (auto it : nums){
            mpp[it]++;
        }

        for(auto it: mpp){
            if(it.second%2!=0){
                return false;
            }
            
        }
        return true;
    }
};