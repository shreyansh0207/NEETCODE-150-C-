class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long count = 0;

        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (arr[i] + arr[j] + arr[k] == target) {
                        count = (count + 1) % MOD;
                    }
                }
            }
        }

        return (int)count;
    }
};