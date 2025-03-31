/*
    1. First, we define a map (`lastOcc`) to store the last occurrence of each character in the string `s`.
    2. We iterate through the string and update the map so each character points to its rightmost index in `s`.
    3. Initialize `partitions` to count the number of valid partitions and `currMax` to track the current maximum index of a partition.
    4. Traverse the string again, updating `currMax` to the furthest position of any character encountered so far.
    5. If the current index equals `currMax`, it means we can form a valid substring, and we increment the `partitions` count.
    6. This ensures that all characters in the current partition do not overlap with subsequent partitions.
    7. Finally, the function returns the total number of partitions, which is stored in `partitions`.
*/

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char, int> lastOcc;
        for (int i = 0; i < s.size(); i++) {
            lastOcc[s[i]] = i;
        }

        int partitions = 0;
        int currMax = 0;
        for (int i = 0; i < s.size(); i++) {
            currMax = max(currMax, lastOcc[s[i]]);
            if (i == currMax) {
                partitions++;
            }
        }
        return partitions;
    }
};