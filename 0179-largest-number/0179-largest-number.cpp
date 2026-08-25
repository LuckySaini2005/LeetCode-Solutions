class Solution {
public:
    static bool cmp(int a, int b) {
        string A = to_string(a);
        string B = to_string(b);

        return A + B < B + A;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        string s="";
        for(int i=nums.size()-1;i>=0;i--){
            s+=to_string(nums[i]);
        }
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) flag =true;
        }
        if(flag==false) return "0";
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna