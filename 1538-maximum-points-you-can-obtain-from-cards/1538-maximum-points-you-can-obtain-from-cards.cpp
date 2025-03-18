class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int max_sum=0;
        int left_sum=0;
        int right_sum=0;

        for (int i=0;i<k;i++){
            left_sum+=arr[i];
        }
        max_sum=left_sum;

        int right_index=arr.size()-1;
        for (int i=k-1;i>=0;i--){
            left_sum-=arr[i];
            right_sum+=arr[right_index--];
            max_sum=max(max_sum,left_sum+right_sum);
        }

return max_sum;
    }
};