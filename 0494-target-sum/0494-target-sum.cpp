class Solution {
public:
    void helper(vector<int>& nums,int idx,int target,int &count){
        if(idx < 0) {
            if(target == 0)
                count++;
            return;
        }

        //taking + sign
        helper(nums,idx-1,target-nums[idx],count);

        //taking - sign
        helper(nums,idx-1,target+nums[idx],count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        helper(nums,n-1,target,count);
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna