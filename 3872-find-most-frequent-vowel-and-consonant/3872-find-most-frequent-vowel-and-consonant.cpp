class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp_vov;
        unordered_map<char,int> mpp_cons;
        for (auto it: s){
            if(it=='a'|| it=='e'|| it=='i'||it=='o'||it=='u'){
                mpp_vov[it]++;
            }
            else{
                mpp_cons[it]++;

            }
        }
        int x=0;
        int y=0;

        for (auto &it :mpp_vov){
            x=max(x,it.second);
        }

        for (auto &it : mpp_cons){
            y=max(y,it.second);
        }

        return x+y;
    }
    
};