class Solution {
public:
    int divide(long long dividend, long long divisor) {
        long long quotient = 0;

        long long div = abs(dividend);
        long long d = abs(divisor);

        while (div >= d) {
            long long temp = d;
            long long count = 1;

            while (div >= temp + temp) {
                temp += temp;
                count += count;
            }

            div -= temp;
            quotient += count;
        }

        if ((divisor < 0 && dividend > 0) ||
            (divisor > 0 && dividend < 0))
            quotient = -quotient;

        // LeetCode 29 overflow case
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return quotient;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna