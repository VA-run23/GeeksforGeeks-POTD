// Generate Usernames

/*
 *    1. The problem asks to generate unique usernames from a given list of usernames.
 *    2. If a username appears for the first time, keep it unchanged.
 *    3. For duplicate usernames, append the occurrence count to make them unique.
 *    4. Maintain:
 *       - freq1 = remaining occurrences of a username.
 *       - freq2 = total occurrences of a username.
 *       - used = all usernames already assigned.
 *    5. For each username:
 *       - If it is the first occurrence, use it directly.
 *       - Otherwise, append a number and keep increasing it until a unique username is found.
 *    6. Mark every generated username as used to avoid future conflicts.
 *    7. Time Complexity: O(n · k), Space Complexity: O(n), where k is the number of suffix attempts.
 */

class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // code here

        map<string, int> freq1, freq2, used;

        for (int i = 0; i < arr.size(); i++) {
            freq1[arr[i]]++;
            freq2[arr[i]]++;
            used[arr[i]] = 1;
        }

        vector<string> ans;

        for (int i = 0; i < arr.size(); i++) {

            int occurrence = freq2[arr[i]] - freq1[arr[i]];

            if (occurrence == 0) {
                ans.push_back(arr[i]);
                freq1[arr[i]]--;
            }
            else {
                string candidate = arr[i] + to_string(occurrence);

                while (used[candidate] == 1) {
                    occurrence++;
                    candidate = arr[i] + to_string(occurrence);
                }

                ans.push_back(candidate);
                used[candidate] = 1;
                freq1[arr[i]]--;
            }
        }

        return ans;
    }
};

// Key Points
// 1. First occurrence of a username remains unchanged.
// 2. Duplicate usernames receive numeric suffixes.
// 3. freq1 tracks remaining occurrences.
// 4. freq2 tracks total occurrences.
// 5. used ensures all generated usernames stay unique.
// 6. Suffix is incremented until an unused name is found.
// 7. Returns a list of unique usernames preserving input order.