//
class Solution {
public:
     int maxEvents(vector<vector<int>>& events) {
        // Sort events based on start day
        sort(events.begin(), events.end());

        // Min heap to store event end days
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 1, i = 0, n = events.size(), attended = 0;

        // Find last possible day (max endDay)
        int lastDay = 0;
        for (auto& e : events) {
            lastDay = max(lastDay, e[1]);
        }

        // Iterate day by day
        for (day = 1; day <= lastDay; ++day) {
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);  // Push endDay
                i++;
            }

            // Remove events that already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend one event (that ends earliest)
            if (!minHeap.empty()) {
                minHeap.pop();
                attended++;
            }
        }

        return attended;
    }
};