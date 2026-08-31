class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current = max(nums[i], current + nums[i]);
            ans = max(ans, current);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna