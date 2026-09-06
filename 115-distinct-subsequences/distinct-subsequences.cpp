class Solution {
public:
    int countUtil(string s1, string s2, int ind1, int ind2,
                  vector<vector<int>>& dp) {
        if (ind2 < 0)
            return 1;
        if (ind1 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int result = 0;
        if (s1[ind1] == s2[ind2]) {
            int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
            int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);
            result = (leaveOne + stay);
        } else {
            result = countUtil(s1, s2, ind1 - 1, ind2, dp);
        }

        dp[ind1][ind2] = result;
        return result;
    }
    int numDistinct(string s, string t) {
        int lt = t.size();
        int ls = s.size();
        // memoization
        //  vector<vector<int>> dp(ls, vector<int>(lt, -1));
        //  return countUtil(s, t, ls - 1, lt - 1, dp);

        // tabulation
        vector<vector<double>> dp(ls + 1, vector<double>(lt + 1, 0));
        for (int i = 0; i <= ls; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= ls; i++) {
            for (int j = 1; j <= lt; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[ls][lt];
        // can do space optimisation
    }
};