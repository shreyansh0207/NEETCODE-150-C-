class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(); int closeSum = 100000;
        int k;int i,j;
        sort(begin(nums) , end(nums));
        for(k=0;k<=n-3;k++){
            i = k+1;
            j = n-1;
            int sum = nums[k] + nums[j] + nums[i];
            while(i<j){
                if(abs(target - sum) < (abs(target-closeSum))){
                    closeSum = sum;
                }
                if(sum < target){
                    i++;
                }
                else {
                    j--;
                }
            }
            
        }
        return closeSum;

    }
};