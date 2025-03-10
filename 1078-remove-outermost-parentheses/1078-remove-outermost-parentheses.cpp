class Solution {
public:
    string removeOuterParentheses(string s) {
         string result = "";
    int balance = 0;  // Track depth of parentheses
    
    for (char c : s) {
        if (c == '(') {
            if (balance > 0) result += c; 
            balance++;
        } else { 
            balance--;
            if (balance > 0) result += c;
        }
    }
    
    return result;
    }
};