class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& ans,
                vector<int>& temp, int idx) {

        // Every current temp is a valid subset
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++) {

            // Skip duplicate elements at the same level
            if(i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            helper(nums, ans, temp, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, ans, temp, 0);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna