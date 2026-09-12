class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int current = nums[0];
        // int ans = nums[0];

        // for (int i = 1; i < nums.size(); i++) {
        //     current = max(nums[i], current + nums[i]);
        //     ans = max(ans, current);
        // }

        // return ans;
        int maxi=INT_MIN;
        int sum=nums[0];
        maxi=max(maxi,sum);
        for(int i=1;i<nums.size();i++){
            if(sum<0) sum=0;
            sum+=nums[i];
             maxi=max(maxi,sum);
            
        }
        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna