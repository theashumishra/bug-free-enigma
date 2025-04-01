#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // dp[i] will store the maximum points achievable from question i onward.
        vector<long long> dp(n + 1, 0); // extra element for ease of boundary handling
        
        // Process questions in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            long long points = questions[i][0];
            int brainpower = questions[i][1];
            int next = i + brainpower + 1;
            // If next goes out of bounds, dp[next] is considered 0.
            long long solve = points + (next < n ? dp[next] : 0);
            long long skip = dp[i + 1];
            dp[i] = max(solve, skip);
        }
        
        return dp[0];
    }
};
