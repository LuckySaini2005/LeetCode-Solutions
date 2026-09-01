class Solution {
public:
    int count=0;
    int helper(int amount,vector<int>& coins,int sum,int idx,int n,vector<vector<int>>& dp){
        if(sum==amount){
            return 1;
        }
        if (sum > amount || idx == coins.size())
            return 0;
            
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        //take the same
       int a= helper(amount,coins,sum+coins[idx],idx,n,dp);
        //taking next
        int b=helper(amount,coins,sum,idx+1,n,dp);
        return dp[idx][sum]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount + 1, -1));
        int sum=0;
        int ans=0;
        if(amount==0) return 1;
       return helper(amount, coins, 0, 0, n,dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna