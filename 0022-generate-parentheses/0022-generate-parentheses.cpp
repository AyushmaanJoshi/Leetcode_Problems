class Solution {
public:
    vector<string> res;

    bool is_valid(const string& str) {
        int count = 0;
        for (char ch : str) {
            if (ch == '(') {
                count++;
            } else {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    void solve(string cur, int n) {
        if (cur.length() == 2 * n) {
            if (is_valid(cur)) {
                res.push_back(cur);
            }
            return;
        }

        solve(cur + "(", n);
        solve(cur + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        solve("", n);
        return res;
    }
};
