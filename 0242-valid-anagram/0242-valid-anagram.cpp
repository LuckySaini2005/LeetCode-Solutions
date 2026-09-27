class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> str1(26,0);
        vector<int> str2(26,0);
        for(int i=0;i<s.size();i++){
            str1[char(s[i])-'a']++;
        }
        for(int i=0;i<t.size();i++){
            str2[char(t[i])-'a']++;
        }
        if(str1==str2) return true;
        else return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna