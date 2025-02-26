class Solution {
  public:
    int subarrayXor(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int count = 0, xorSum = 0;
        
        for (int num : arr) {
            xorSum ^= num;//xor of subarray
            
            if (xorSum == k) {
                count++;//if xor == k, increase the count
            }
            
            if (freq.find(xorSum ^ k) != freq.end()) {
                count += freq[xorSum ^ k];//if there exist value == xorSum ^ k in the freq map, add its frequency
            }
            
            freq[xorSum]++;//increase the count of the xorSum in the map
        }
        return count;
    }
};

////EXPLANATION:
// The code uses XOR and a hash map to efficiently count subarrays with XOR sum equal to k.
// 1. A hash map (unordered_map) is used to store the frequency of XOR prefix sums.
// 2. Initialize count of subarrays to 0 and current XOR sum to 0.
// 3. Iterate through the array:
//    a. Update the current XOR sum by performing XOR with the current element.
//    b. If the current XOR sum is equal to k, increment the count.
//    c. Check if the XOR of the current XOR sum and k (xorSum ^ k) exists in the hash map. 
//       This checks if there's a prefix sum that, when XORed with the current XOR sum, results in k.
//    d. If (xorSum ^ k) exists in the hash map, add the count of such XOR prefix sums to count. 
//       This means there are subarrays ending at the current element with XOR sum equal to k.
//    e. Update the hash map with the current XOR sum by incrementing its count.
// 4. Return the total count of subarrays with XOR sum equal to k.