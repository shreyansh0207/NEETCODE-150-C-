class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int ,int >freq;
        int i;
        for(i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        
        int maxLength = 0;
        for (auto it : freq) {
            int num = it.first;
            if (freq.find(num + 1) != freq.end()) {
                int length = freq[num] + freq[num + 1];
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
        return maxLength;
    }
};