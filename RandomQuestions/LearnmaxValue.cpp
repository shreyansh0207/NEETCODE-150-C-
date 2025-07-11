class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        
        sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });

        int n = events.size();

        
        vector<int> endTimes(n);
        for (int i = 0; i < n; ++i) endTimes[i] = events[i][1];

       
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int start = events[i - 1][0];
            int end = events[i - 1][1];
            int val = events[i - 1][2];

            
            int l = 0, r = i - 1;
            while (l < r) {
                int m = (l + r + 1) / 2;
                if (endTimes[m - 1] < start)
                    l = m;
                else
                    r = m - 1;
            }
            int prev = (l > 0 && endTimes[l - 1] < start) ? l : 0;

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + val);
            }
        }

        return dp[n][k];
    }
};