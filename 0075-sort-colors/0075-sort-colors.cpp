class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            if(nums[i]==1) one++;
            if(nums[i]==2) two++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<zero) nums[i]=0;
            if(i>=zero && i<one+zero) nums[i]=1;
            if(i>=one+zero) nums[i]=2;
        }


    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna