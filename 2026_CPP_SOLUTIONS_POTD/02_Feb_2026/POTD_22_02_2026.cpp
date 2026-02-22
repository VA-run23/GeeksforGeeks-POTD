/*
    1. This function counts the number of subarrays whose XOR equals a given value k.
    2. It uses a running prefix XOR (xorSum) to track cumulative XOR values while iterating.
    3. If xorSum itself equals k, that means a subarray from the start to current index matches.
    4. The map 'freq' stores frequencies of prefix XORs seen so far.
    5. For each element, if (xorSum ^ k) exists in freq, it means a subarray ending here has XOR = k.
    6. The count is incremented accordingly, and xorSum is added to freq for future checks.
    7. Time Complexity: O(n), Space Complexity: O(n), where n = size of arr.
*/

class Solution {
  public:
    int subarrayXor(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int count = 0, xorSum = 0;
        
        for (int num : arr) {
            xorSum ^= num;
            
            if (xorSum == k) {
                count++;
            }
            
            if (freq.find(xorSum ^ k) != freq.end()) {
                count += freq[xorSum ^ k];
            }
            
            freq[xorSum]++;
        }
        return count;
    }
};

// Key points:
// - The algorithm leverages prefix XOR to avoid recomputing subarray XORs repeatedly.
// - The unordered_map acts as a frequency dictionary for previously seen XOR values.
// - The trick is that xorSum ^ k gives the required prefix XOR that makes a subarray XOR = k.
// - This approach is optimal compared to brute force O(n^2) checking of all subarrays.
// - Time complexity is linear, O(n), and space complexity is O(n) due to the hash map.
