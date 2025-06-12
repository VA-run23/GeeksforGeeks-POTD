/*
    1. Filter out x from the array to ensure it is not included in the closest elements.
    2. Compute absolute distances of remaining elements from x and store them in a vector.
    3. Sort the elements based on their absolute distance from x, preferring larger numbers in case of ties.
    4. Extract the k closest elements from the sorted list.
    5. Return the k closest elements in order of closeness.
    6. Time Complexity: O(n log n) due to sorting, where n is the number of elements in arr.
    7. Space Complexity: O(n) due to storing filtered elements and distance pairs separately.
*/

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
    vector<int> filtered;
    for (int num : arr) {
        if (num != x) {
            filtered.push_back(num);
        }
    }
    
    vector<pair<int, int>> distances;
    for (int num : filtered) {
        distances.push_back({num, abs(num - x)});
    }
    sort(distances.begin(), distances.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first; 
    });
    
    vector<int> result;
    for (int i = 0; i < k && i < distances.size(); i++) {
        result.push_back(distances[i].first);
    }
    
    return result;
    }
};
