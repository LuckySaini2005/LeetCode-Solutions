class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        // If all digits were 9
        digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna