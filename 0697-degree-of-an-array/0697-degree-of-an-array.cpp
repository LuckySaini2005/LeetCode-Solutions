class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(50000, 0);
        vector<int> first(50000, -1);
        vector<int> last(50000, -1);

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;

            if(first[nums[i]] == -1)
                first[nums[i]] = i;

            last[nums[i]] = i;
        }

        int maxi = 0;
        for(int i = 0; i < 50000; i++) {
            maxi = max(maxi, freq[i]);
        }

        int ans = n;

        for(int i = 0; i < 50000; i++) {
            if(freq[i] == maxi) {
                ans = min(ans, last[i] - first[i] + 1);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna