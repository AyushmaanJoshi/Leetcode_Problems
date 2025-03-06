class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int > res;
        unordered_map<int,int> mpp;
        int n =grid.size()*grid.size();
        int sum=0;

        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[i].size();j++){
                mpp[grid[i][j]]++;
                sum+=grid[i][j];

            }
        }
         
        int total_sum= ( n * (n + 1))/ 2;


        for (auto it : mpp){
            if (it.second==2){
                sum=sum-it.first;
                res.push_back(it.first);
            }
        }
        int missing_no=total_sum-sum;
        res.push_back(missing_no);
        return res;
    }
};