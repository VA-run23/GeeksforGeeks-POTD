/*
    1. This function generates binary numbers from 1 to n using a clever iterative approach.
    2. It initializes a vector 'result' of size n and sets the first binary number as "1".
    3. For each number i from 2 to n, it builds the binary string by copying the binary of i/2.
    4. Then it appends '0' if i is even, or '1' if i is odd, effectively simulating binary construction.
    5. This method avoids repeated division and reversal, making it more efficient than naive conversion.
    6. Time Complexity: O(n) — each binary string is built in constant time due to reuse.
    7. Space Complexity: O(n) — storing n binary strings in the result vector.
*/

class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> result(n);
        result[0] = "1";
        for(int i = 2;i<=n;i++){
            result[i-1] = result[(i/2)-1];
            if(i%2 == 0){
                result[i-1].push_back('0'); 
            }
            else{
                result[i-1].push_back('1'); 
            }
        }
        return result;
    }
};