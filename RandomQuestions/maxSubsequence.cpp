class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       int n = nums.size();

        // Step 1: Create a new array to store value and index
        vector<pair<int, int>> valueIndex;

        // Step 2: Store nums[i] and its index
        for (int i = 0; i < n; i++) {
            valueIndex.push_back({nums[i], i});
        }

        // Step 3: Sort in descending order by value
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (valueIndex[i].first < valueIndex[j].first) {
                    swap(valueIndex[i], valueIndex[j]);
                }
            }
        }
        vector<int> topIndexes;
        for(int i=0;i<k;i++){
           topIndexes.push_back(valueIndex[i].second); 
        }

        for(int i=0;i<k-1;i++){
            for(int j=i+1;j<k;j++){
                if(topIndexes[i] > topIndexes[j]){
                    swap(topIndexes[i] , topIndexes[j]);
                }
            }
        }



        
          vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(nums[topIndexes[i]]);
        }

        return result;
    }
};