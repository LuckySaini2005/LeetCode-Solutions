class Solution {
public:
    int helper(vector<int>& coins, int amount, int idx,
               vector<vector<int>>& dp) {

        if (amount == 0)
            return 0;

        if (amount < 0 || idx >= coins.size())
            return 1e9;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        // Take current coin
        int take = 1 + helper(coins, amount - coins[idx], idx, dp);

        // Skip current coin
        int skip = helper(coins, amount, idx + 1, dp);

        return dp[idx][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(coins, amount, 0, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna