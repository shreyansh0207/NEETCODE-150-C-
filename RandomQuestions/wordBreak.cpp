class Solution {
public:
       unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};

        vector<string> result;
        for (int i = 1; i <= s.size(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> subList = dfs(s.substr(i));
                for (string sub : subList) {
                    result.push_back(word + (sub.empty() ? "" : " " + sub));
                }
            }
        }

        return memo[s] = result;
    }
};