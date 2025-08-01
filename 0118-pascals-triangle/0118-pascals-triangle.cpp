class Solution {
public:
    vector<int> generaterow(int row){
        vector<int> row_ans;
        long long ans =1;
        row_ans.push_back(1);

        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans/=col;
            row_ans.push_back(ans);
        }
        return row_ans;
    }
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>>ans;
        for (int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};