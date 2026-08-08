class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> arr(2,0);
       for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                long long sum=nums[i]+nums[j];
                if(sum==target){
                    arr[0]=i;arr[1]=j;
                }
            }       
        } 
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna