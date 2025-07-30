/* 
    1. We initialize a count and a prefix sum variable, along with a hashmap to store frequency of prefix sums.
    2. We set prefixSumFreq[0] = 1 to handle cases where the subarray starts from index 0.
    3. As we iterate through the array, we keep updating the cumulative sum.
    4. For each sum, we check if (sum - k) exists in the hashmap—this tells us a valid subarray ends at this index.
    5. If it exists, we add its frequency to our count since each one represents a distinct valid subarray.
    6. We then update the hashmap with the current sum’s frequency for future checks.
    7. Time complexity is O(n) and space complexity is O(n) due to one pass and hashmap storage.
*/

class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int count = 0, sum = 0;
        unordered_map<int, int> psumFreq;
        psumFreq[0] = 1; 

        for (int num : arr) {
            sum += num;

            if (psumFreq.find(sum - k) != psumFreq.end()) {
                count += psumFreq[sum - k];
            }


            psumFreq[sum]++;
        }

        return count;
    }
};
