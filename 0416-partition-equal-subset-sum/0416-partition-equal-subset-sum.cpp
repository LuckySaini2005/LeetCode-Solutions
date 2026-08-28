class Solution {
public:
    bool helper(vector<int>& nums,int total,int idx,int sum,vector<vector<int>>& dp){
        if(idx<0){
            if(total-sum==sum) return true;
            else return false;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        //not take condition
        return dp[idx][sum]=helper(nums,total,idx-1,sum,dp) || helper(nums,total,idx-1,sum+nums[idx],dp);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;

        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(total, -1));
        return helper(nums,total,n-1,0,dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna