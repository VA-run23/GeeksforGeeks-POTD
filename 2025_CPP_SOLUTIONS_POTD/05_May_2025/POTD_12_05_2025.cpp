// User function Template for C++
// This solution optimally assigns meetings to rooms while handling delays.
// It uses two min-heaps:
//   1. `availableRooms`: Tracks available rooms in increasing order.
//   2. `usedRooms`: Tracks rooms currently occupied (sorted by release time).
// The approach ensures:
//   - Meetings are assigned to the lowest available room.
//   - If no rooms are free, meetings are delayed until the earliest room frees up.
//   - The room that hosts the most meetings is identified efficiently.
// Complexity Analysis:
//   - Sorting meetings: O(m log m)
//   - Processing meetings: O(m log n)
//   - Overall Complexity: O(m log m + m log n), where m is the number of meetings and n is the number of rooms.

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
    
        sort(meetings.begin(), meetings.end()); 
        priority_queue<int, vector<int>, greater<int>> avlRooms;
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> usr;
        vector<int> cnt(n, 0); 

        for (int i = 0; i < n; ++i) avlRooms.push(i); 

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];


            while (!usr.empty() && usr.top().first <= start) {
                avlRooms.push(usr.top().second);
                usr.pop();
            }

            if (!avlRooms.empty()) {

                int room = avlRooms.top();
                avlRooms.pop();
                usr.push({end, room});
                cnt[room]++;
            }  else {
                pair<long, int> topElement = usr.top(); 
                usr.pop();
                usr.push({topElement.first + (end - start), topElement.second});
                cnt[topElement.second]++;
            }

        }

        return distance(cnt.begin(), max_element(cnt.begin(), cnt.end()));
    }
};