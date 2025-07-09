class Solution {
public:
vector<string>res;
void solve(string str,int open ,int close,int n){
    if(str.size()==2*n) {
    res.push_back(str);
    return ;
    }

if(open<n){
    solve(str+"(",open+1,close,n);
    
}if(close<open){
    solve(str+")",open,close+1,n);
}
}
vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return res;
    }

};