class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        int count=1;
        int idx;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                 count++;
            }
            maxi=max(maxi,count);
            if(maxi==count) idx=i;
            if(nums[i]!=nums[i+1]) count=0;
        }
        return nums[idx];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna