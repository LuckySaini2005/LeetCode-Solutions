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

   for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
        if (v[i].second < v[j].second) {
            swap(v[i], v[j]);
        }
    }
    }

    string ans = "";

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second; j++) {
            ans += v[i].first;
        }
    }
    return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna