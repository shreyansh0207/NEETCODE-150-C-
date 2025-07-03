class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();int i,j; vector<int>result(n);
        for(i=0;i<n;i++){
            int product = 1;
            for(j=0;j<n;j++){
                if(i!=j){
                    product *= nums[j];
                }
            }
            result[i] = product;
        }
        return result;
    }
};