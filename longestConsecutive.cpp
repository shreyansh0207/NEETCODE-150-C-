class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin() , nums.end());

        int i;
        int n = nums.size();
        int longest = 1;
        int current = 1;
        for(i=0;i<n;i++){
            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1] + 1){
                current++;
            }
            else {
            longest = max(longest,current);
            current = 1;
            }
        }
        return max(longest , current);
    }

};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> numSet(nums.begin(), nums.end());
//         int longest = 0;

//         for (int num : numSet) {
//             // Only start if it's the beginning of a sequence
//             if (numSet.find(num - 1) == numSet.end()) {
//                 int currentNum = num;
//                 int count = 1;

//                 // Count up the sequence
//                 while (numSet.find(currentNum + 1) != numSet.end()) {
//                     currentNum++;
//                     count++;
//                 }

//                 longest = max(longest, count);
//             }
//         }

//         return longest;
//     }

// };