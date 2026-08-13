class Solution {
public:

    void solve(vector<int>& nums,vector<int>& current,vector<vector<int>>& result,int idx,int n){
        if(idx>=n){
             result.push_back(current);
            return;
        }
        //take condition
        solve(nums,current,result,idx+1,n);
        current.push_back(nums[idx]);

        //not take 
        solve(nums,current,result,idx+1,n);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        int n=nums.size();
        solve(nums,current,result,0,n);
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna