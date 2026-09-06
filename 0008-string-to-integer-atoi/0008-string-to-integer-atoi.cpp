class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Build number
        long long num = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            num = num * 10 + digit;

            // 4. Check overflow
            if (num * sign > INT_MAX)
                return INT_MAX;

            if (num * sign < INT_MIN)
                return INT_MIN;

            i++;
        }

        return num * sign;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna