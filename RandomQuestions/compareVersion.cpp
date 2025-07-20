class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        int n = max(v1.size(), v2.size());

        for (int i = 0; i < n; ++i) {
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }

        return 0;
    }

private:
    // Helper function to split version string into integers
    vector<int> split(const string& version) {
        vector<int> result;
        int num = 0;

        for (int i = 0; i < version.size(); ++i) {
            if (version[i] == '.') {
                result.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (version[i] - '0');
            }
        }
        result.push_back(num);  // add the last segment
        return result;
    }
};