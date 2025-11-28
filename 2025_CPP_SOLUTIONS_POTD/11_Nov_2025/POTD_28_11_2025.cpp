/*
   1. The function subsetXOR(int n) aims to return a subset of numbers from 1 to n whose XOR equals n.
   2. If n == 1, the subset is simply {1}, since XOR(1) = 1, so it directly returns {1}.
   3. Otherwise, it initializes a vector ans with all integers from 1 to n.
   4. The cumulative XOR of numbers from 1 to n follows a repeating pattern depending on n % 4.
   5. Based on this pattern, one element is removed to adjust the XOR sum to equal n:
      - If n % 4 == 1 → remove (n-1).
      - If n % 4 == 2 → remove 1.
      - If n % 4 == 3 → remove n.
   6. If n % 4 == 0, no removal is needed because XOR(1..n) already equals n.
   7. Time Complexity: O(n) (due to filling the vector and possibly erasing one element).
      Space Complexity: O(n) (for storing the subset in the vector).
*/


class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans;
        if(n==1){
            ans.push_back(n);  
            return ans; 
        }
        
        for(int i=1;i<=n;i++){
            ans.push_back(i) ;
        }
        if(n%4 == 1) ans.erase(ans.begin() + n - 2); 
        if(n%4 == 2) ans.erase(ans.begin());        
        if(n%4 == 3) ans.erase(ans.begin() + n - 1);        

        return ans ;
    }
};