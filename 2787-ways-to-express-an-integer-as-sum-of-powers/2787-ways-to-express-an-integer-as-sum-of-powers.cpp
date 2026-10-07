
class Solution {
public:
    int numberOfWays(int n, int x) {
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // 1 way to form a sum of 0 (using no elements)

        for (int i = 1; ; ++i) {
            long long power = pow(i, x);
            if (power > n) break; // Stop when i^x exceeds n

            int val = (int)power;
            // Traverse backward to ensure each power is used at most once (0/1 Knapsack)
            for (int j = n; j >= val; --j) {
                dp[j] = (dp[j] + dp[j - val]) % MOD;
            }
        }

        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna