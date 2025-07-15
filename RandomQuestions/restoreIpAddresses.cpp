//
class Solution {
public:
    vector<string> result;

    bool isValid(const string& s) {
        if (s.length() > 1 && s[0] == '0') return false; // no leading zero
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string& s, int start, int dots, string path) {
        if (dots == 4 && start == s.length()) {
            path.pop_back(); 
            result.push_back(path);
            return;
        }

        if (dots > 4) return; 

        for (int len = 1; len <= 3 && start + len <= s.length(); ++len) {
            string part = s.substr(start, len);
            if (isValid(part)) {
                backtrack(s, start + len, dots + 1, path + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.length() < 4 || s.length() > 12) return result; 
        backtrack(s, 0, 0, "");
        return result;
    }
};