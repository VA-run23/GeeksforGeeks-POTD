/*
    This function finds the single element in the array arr that appears only once while all other elements appear three times. 
    1. The algorithm iterates through all 64 bits (assuming integers are 64-bit) to count the occurrence of each bit across all elements. 
    2. If the count of a bit at a particular position is not divisible by 3, that bit is set in the final result.
    3. The result variable is used to construct the number by setting the appropriate bits using bitwise OR and left shift.
    4. The nested loops ensure we check every bit of every element in the array to compute its contribution to the result.
    5. Time Complexity: The algorithm runs in O(64 * n), which simplifies to O(n) since 64 is constant.
    6. Space Complexity: The algorithm uses O(1) extra space as only a few variables (result and sum) are utilized.
    7. Efficient for handling large input arrays where traditional methods may struggle due to frequent element occurrences.
*/


class Solution {
    public:
      int getSingle(vector<int> &arr) {
          // code here
         
          int result = 0;
          
          for (int i = 0; i < 64; i++) {
              int sum = 0; 
              for (int j = 0; j < arr.size(); j++) { 
                  if ((arr[j] >> i) & 1) { 
                      sum++;
                  }
              }
              if (sum % 3 != 0) { 
                  result |= (1 << i);
              }
          }
          return result; 
      }
  };