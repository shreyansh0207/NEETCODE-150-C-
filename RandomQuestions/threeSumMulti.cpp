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



// class Solution {
// public:
//     int threeSumMulti(vector<int>& arr, int target) {
//         const int MOD = 1e9 + 7;
//         long long ans = 0;
//         vector<long long> freq(101, 0); 

//         for (int num : arr) {
//             freq[num]++;
//         }

//         for (int i = 0; i <= 100; ++i) {
//             for (int j = i; j <= 100; ++j) {
//                 int k = target - i - j;
//                 if (k < 0 || k > 100) continue;

               
//                 if (i == j && j == k) {
//                     ans += (freq[i] * (freq[i] - 1) * (freq[i] - 2)) / 6;
//                 } else if (i == j && j != k) {
//                     ans += (freq[i] * (freq[i] - 1) / 2) * freq[k];
//                 } else if (i < j && j < k) {
//                     ans += freq[i] * freq[j] * freq[k];
//                 }
              
//             }
//         }

//         return ans % MOD;
//     }
// };