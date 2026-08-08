class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (mp.find(diff) != mp.end()) {
                return {mp[diff], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna