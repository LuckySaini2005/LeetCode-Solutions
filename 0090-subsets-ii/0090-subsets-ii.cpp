class Solution {
public:

    bool search(vector<int>& temp, vector<vector<int>>& dp) {
        for(int i = 0; i < dp.size(); i++) {
            if(temp.size() == dp[i].size()) {
                if(temp == dp[i])
                    return true;
            }
        }
        return false;
    }

    void helper(vector<int>& nums, vector<vector<int>>& dp,
                vector<int>& temp, int idx, int n) {

        if(idx >= n) {
            if(!search(temp, dp))
                dp.push_back(temp);
            return;
        }

        // Don't take
        helper(nums, dp, temp, idx + 1, n);

        // Take
        temp.push_back(nums[idx]);
        helper(nums, dp, temp, idx + 1, n);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());   

        vector<vector<int>> dp;
        vector<int> temp;

        int n = nums.size();

        helper(nums, dp, temp, 0, n);

        return dp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna