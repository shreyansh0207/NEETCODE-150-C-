class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, tank = 0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i] - cost[i];
            tank += gas[i] - cost[i];

         if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        
        return (totalGas >= 0) ? start : -1;
    }
};