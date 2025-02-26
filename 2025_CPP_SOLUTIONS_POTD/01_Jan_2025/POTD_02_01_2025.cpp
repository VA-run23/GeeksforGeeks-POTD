// User function Template for C++

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0, sum = 0;
        prefixSumCount[0] = 1;
        
        for (int num : arr) {
            sum += num;
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }
            prefixSumCount[sum]++;
        }
        return count;
    }
};
///EXPLANATION:

/// EXPLANATION:
// The code uses prefix sums and a hash map to efficiently count subarrays with sum equal to k.
// 1. A hash map (unordered_map) is used to store the count of prefix sums.
// 2. Initialize count of subarrays to 0 and current prefix sum to 0.
// 3. Add an entry in the hash map with key 0 and value 1 to handle subarrays starting from the beginning.
// 4. Iterate through the array:
//    a. Update the current prefix sum by adding the current element.
//    b. Check if the difference (sum - k) exists in the hash map. This checks if there's a prefix sum that,
// when subtracted from the current prefix sum, results in k.
//    c. If (sum - k) exists in the hash map, add the count of such prefix sums to count. This means there are 
//   subarrays ending at the current element with sum equal to k.
//    d. Update the hash map with the current prefix sum by incrementing its count.
// 5. Return the total count of subarrays with sum equal to k.