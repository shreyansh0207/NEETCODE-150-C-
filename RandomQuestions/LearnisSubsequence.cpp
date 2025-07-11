class Solution {
public:
bool isSubsequence(const string& s, const string& target) {
        int i = 0, j = 0;
        while (i < s.size() && j < target.size()) {
            if (s[i] == target[j]) j++;
            i++;
        }
        return j == target.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        string candidates;
        for (auto& [c, cnt] : freq) {
            if (cnt >= k) candidates += c;
        }

        
        sort(candidates.begin(), candidates.end(), greater<char>());

        string result;

        function<void(string)> dfs = [&](string cur) {
            if (cur.size() > s.size() / k) return;

            string repeated;
            for (int i = 0; i < k; ++i) repeated += cur;

            if (isSubsequence(s, repeated)) {
                if (cur.size() > result.size() || (cur.size() == result.size() && cur > result)) {
                    result = cur;
                }

                for (char c : candidates) {
                    dfs(cur + c);
                }
            }
        };

        dfs("");

        return result;
    }
};