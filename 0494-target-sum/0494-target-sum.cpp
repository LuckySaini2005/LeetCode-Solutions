class Solution {
public:
    int helper(vector<int>& nums,int idx,int target,vector<unordered_map<int,int>>& dp){
        if(idx < 0) {
            return target == 0;
        }
        if(dp[idx].count(target))
            return dp[idx][target];
        //taking + sign
        int add = helper(nums, idx - 1,target - nums[idx], dp);
        //taking - sign
        int subtract = helper(nums, idx - 1,target + nums[idx], dp);
        return dp[idx][target] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n);
        return helper(nums,n-1,target,dp);
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna