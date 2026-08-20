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
       
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
         int prev1=nums[0];
        int prev2=max(nums[0],nums[1]);
        int curr;
        for(int i=2;i<n;i++){
            curr=max(nums[i]+prev1,prev2);
            prev1=prev2;
            prev2=curr;
        }
    return curr;    
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna