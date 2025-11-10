/*
    1. Initialize three states: `hold` (profit if holding a stock), `sold` (profit if sold today), and `rest` (profit if resting/cooldown).
    2. On day 0: `hold = -arr[0]` (buying the stock), `sold = INT_MIN` (cannot sell yet), `rest = 0` (no action).
    3. For each day i, store yesterday’s `sold` in `prevSold` to handle the cooldown transition.
    4. Update `sold = hold + arr[i]` meaning if you sell today, profit comes from yesterday’s hold plus today’s price.
    5. Update `hold = max(hold, rest - arr[i])` meaning either keep holding or buy today after resting yesterday.
    6. Update `rest = max(rest, prevSold)` meaning either continue resting or enter cooldown after selling yesterday.
    7. Final answer is `max(sold, rest)` since ending with a stock in hand (`hold`) is invalid; Time Complexity = O(n), Space Complexity = O(1).
*/

class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        // code here
        
        if (arr.empty()) return 0;

        int hold = -arr[0];   
        int sold = INT_MIN;      
        int rest = 0;          

        for (int i = 1; i < arr.size(); i++) {
            int prevSold = sold; 

        
            sold = hold + arr[i];                
            hold = max(hold, rest - arr[i]);   
            rest = max(rest, prevSold);            
        }

        return max(sold, rest); 
    }
};