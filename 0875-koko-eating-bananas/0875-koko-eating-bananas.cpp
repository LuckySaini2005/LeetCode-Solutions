class Solution {
public:
    bool canFinish(vector<int>& piles, int k, int h) {
        long long hr = 0;
        for(int pile : piles) {
            hr += (pile - 1) / k + 1;
        }
        return hr <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canFinish(piles, mid, h)) {
                ans = mid;       
                high = mid - 1;   
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna