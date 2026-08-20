class Solution {
public:
int helper1(vector<int> &nums,vector<int> &dp1,int idx){

    if(idx==1) return nums[idx];
    if(idx<1) return 0;
    if(dp1[idx]!=-1) return dp1[idx];
    int take=nums[idx]+helper1(nums,dp1,idx-2);
    int nottake=0+helper1(nums,dp1,idx-1);
    return dp1[idx]=max(take,nottake);
}
int helper2(vector<int> &nums,vector<int> &dp2,int idx){

    if(idx==0) return nums[idx];
    if(idx<0) return 0;
    if(dp2[idx]!=-1) return dp2[idx];
    int take=nums[idx]+helper2(nums,dp2,idx-2);
    int nottake=0+helper2(nums,dp2,idx-1);
    return dp2[idx]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        if(n==1) return nums[0];
        return max(helper1(nums,dp1,n-1),helper2(nums,dp2,n-2));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna