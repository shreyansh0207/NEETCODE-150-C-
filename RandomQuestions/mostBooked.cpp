//Learn
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> count(n, 0); 

        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; i++) free_rooms.push(i);

        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy_rooms;

        for (auto& meet : meetings) {
            int start = meet[0];
            int end = meet[1];

            
            while (!busy_rooms.empty() && busy_rooms.top().first <= start) {
                free_rooms.push(busy_rooms.top().second);
                busy_rooms.pop();
            }

            if (!free_rooms.empty()) {
                int room = free_rooms.top(); free_rooms.pop();
                count[room]++;
                busy_rooms.push({end, room});
            } else {
                
                auto [avail_time, room] = busy_rooms.top(); busy_rooms.pop();
                count[room]++;
                long long duration = end - start;
                busy_rooms.push({avail_time + duration, room});
            }
        }

       
        int max_count = -1, res = -1;
        for (int i = 0; i < n; ++i) {
            if (count[i] > max_count) {
                max_count = count[i];
                res = i;
            }
        }

        return res;
    }
};