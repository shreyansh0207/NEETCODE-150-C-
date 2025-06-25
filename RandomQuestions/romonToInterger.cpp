class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;

        for (int i = 0; i < s.length(); i++) {
            // Get the value of current symbol
            int current = romanValue[s[i]];

            // If next symbol exists and is greater, subtract current
            if (i + 1 < s.length() && romanValue[s[i]] < romanValue[s[i + 1]]) {
                total -= current;
            } else {
                total += current;
            }
        }

        return total;
    }
};