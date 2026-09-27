class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> idx;
        if (s.size() < p.size()) return idx;

        vector<int> strp(26, 0);
        vector<int> strs(26, 0);

        // 1. Build initial frequency maps for the first window
        for (int i = 0; i < p.size(); i++) {
            strp[p[i] - 'a']++;
            strs[s[i] - 'a']++;
        }

        // 2. Use '<=' to make sure the final window is checked
        for (int i = 0; i <= s.size() - p.size(); i++) {
            if (strs == strp) {
                idx.push_back(i);
            }
            
            // 3. Only slide if there is another character left in string 's'
            if (i < s.size() - p.size()) {
                strs[s[i] - 'a']--;               // Remove the outgoing character
                strs[s[i + p.size()] - 'a']++;    // Corrected index: s[i + p.size()]
            }
        }
        
        return idx;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna