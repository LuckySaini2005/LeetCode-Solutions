class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;

        int prev2 = 1; // Represents dp[i-2]
        int prev1 = 1; // Represents dp[i-1]

        for (size_t i = 1; i < s.length(); ++i) {
            int current = 0;

            // Single digit decode (1-9)
            if (s[i] != '0') {
                current += prev1;
            }

            // Two digit decode (10-26)
            int twoDigit = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna