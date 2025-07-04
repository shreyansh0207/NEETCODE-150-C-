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