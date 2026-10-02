class Solution {
public:
 void generateParenthesisHelper(int open, int close, string current, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }

    if (open > 0) {
        generateParenthesisHelper(open - 1, close, current + "(", result);
    }
    if (close > open) {
        generateParenthesisHelper(open, close - 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n, n, "", result);
    return result;
}
    
};