class Solution {
public:
int helper(vector<int> &nums,vector<int> &dp,int idx){

    if(idx==0) return nums[idx];
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int take=nums[idx]+helper(nums,dp,idx-2);
    int nottake=0+helper(nums,dp,idx-1);
    return dp[idx]=max(take,nottake);
}


    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
    return dp[n-1];    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna