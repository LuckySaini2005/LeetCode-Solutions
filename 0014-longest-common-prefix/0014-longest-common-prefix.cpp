#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";
        
        // Loop through each character of the first string
        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            
            // Compare character 'c' with the same position in all other strings
            for (int j = 1; j < strs.size(); ++j) {
                // If index exceeds a string's length or characters mismatch, return the prefix found so far
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna