class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;

    for (char c : s) {
        mp[c]++;
    }

    vector<pair<char, int>> v;

    for (auto x : mp) {
        v.push_back({x.first, x.second});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    string ans = "";

    for (auto x : v) {
        ans += string(x.second, x.first);
    }
    return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna