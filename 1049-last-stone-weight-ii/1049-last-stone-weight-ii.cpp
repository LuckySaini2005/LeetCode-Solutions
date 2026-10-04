class Solution {
private:
    int solve(int index, int currentSum, const vector<int>& stones, int target, vector<vector<int>>& dp) {
        // Base case: processed all stones or reached exact target
        if (index == stones.size() || currentSum == target) {
            return currentSum;
        }
        // Return cached result if already calculated
        if (dp[index][currentSum] != -1) {
            return dp[index][currentSum];
        }
        // Choice 1: Exclude the current stone
        int exclude = solve(index + 1, currentSum, stones, target, dp);
        // Choice 2: Include the current stone (if it stays within target capacity)
        int include = 0;
        if (currentSum + stones[index] <= target) {
            include = solve(index + 1, currentSum + stones[index], stones, target, dp);
        }
        // Store and return the maximum achievable subset sum
        return dp[index][currentSum] = max(include, exclude);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for (int stone : stones) {
            totalSum += stone;
        }
        int target = totalSum / 2;
        int n = stones.size();

        // dp[index][currentSum] initialized to -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Find the maximum subset sum <= target starting from index 0
        int s2 = solve(0, 0, stones, target, dp);

        // Result is S1 - S2 = (totalSum - S2) - S2
        return totalSum - 2 * s2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna