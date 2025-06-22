#define ll long long
class Solution {
public:
    int longestPalindromeSubseq(const string& s) {
        int n = s.size();
        if (n == 0) return 0;

        // dp[i][j] = length of LPS in s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Subsequences of length 1 are palindromes of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Build up from substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    // If two ends match, we take the inner LPS and add 2
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    // Otherwise, drop one end and take the better of the two
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        // The answer is LPS over the whole string
        return dp[0][n-1];
    }
};
