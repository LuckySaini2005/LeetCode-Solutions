class Solution {
public:
    vector<int> houses;
    vector<vector<int>> dp;

    int cost(int i, int j) {
        int mid = (i + j) / 2;
        int ans = 0;

        for (int x = i; x <= j; x++) {
            ans += abs(houses[x] - houses[mid]);
        }

        return ans;
    }

    int f(int idx, int k) {
        int n = houses.size();

        if (k == 1) {
            return cost(idx, n - 1);
        }

        if (dp[idx][k] != -1)
            return dp[idx][k];

        int ans = 1e9;

        // Leave at least (k-1) houses for remaining mailboxes
        for (int j = idx; j <= n - k; j++) {
            int currentCost = cost(idx, j);
            int remainingCost = f(j + 1, k - 1);

            ans = min(ans, currentCost + remainingCost);
        }

        return dp[idx][k] = ans;
    }

    int minDistance(vector<int>& h, int k) {
        houses = h;
        sort(houses.begin(), houses.end());

        int n = houses.size();
        dp.resize(n, vector<int>(k + 1, -1));

        return f(0, k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna