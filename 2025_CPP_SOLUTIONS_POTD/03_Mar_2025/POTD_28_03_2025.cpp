/*
    1. The function determines the maximum number of non-overlapping activities that can be selected.
    2. It pairs activity start and finish times into a vector, with finish times as the first element to aid sorting.
    3. The activities are sorted by their finish times to facilitate greedy selection of non-overlapping ones.
    4. The first activity is always selected, initializing the count and setting its finish time as the comparison point.
    5. Iterating through the sorted activities, it checks if the start time of the current activity is after the last selected one's finish time.
    6. If true, it increments the count and updates the last selected activity's finish time.
    7. Finally, the function returns the total count of selected non-overlapping activities.
*/

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int, int>> act;

        for (int i = 0; i < n; i++) {
            act.push_back({finish[i], start[i]});
        }

        sort(act.begin(), act.end());

        int count = 1; 
        int finLast = act[0].first;

        for (int i = 1; i < n; i++) {
            if (act[i].second > finLast) {
                count++;
                finLast = act[i].first;
            }
        }
        
        return count;
    }
};