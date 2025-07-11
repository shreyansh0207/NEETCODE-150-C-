class Solution {
public:
//esme we see the concept of the min heap : means (largest , top , greatest) aata and in max heap (smallest , top , least) aata hai
//esme we see the concept of the min heap : means (largest , top , greatest) :: Simple hota hai 
//https://youtu.be/7VoJn544QrM?feature=shared
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; 
    for(auto& [num,freq] : freqMap){
        minHeap.push({freq,num});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    vector<int>result;
    while(!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop(); //esme eak eak karke element pop hota jayega 
    }
    return result;




    }
};