class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);  
        }
        int idx1=0;
        int idx2=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                ans.push_back(pos[idx1]);
                idx1++;
            }
            else{
                ans.push_back(neg[idx2]);
                idx2++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna