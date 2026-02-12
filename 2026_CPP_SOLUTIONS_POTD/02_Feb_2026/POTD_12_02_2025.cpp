/*
    1. The problem is to maximize the minimum height of plants after distributing at most k units of water, each affecting w consecutive plants.  
    2. The 'check' function verifies if a target minimum height 'mid' can be achieved with the given water distribution.  
    3. It uses a prefix array 'Pref' to simulate range updates efficiently, applying water additions and rolling back after w positions.  
    4. If any plant’s height is below 'mid', the required water is added, and if it exceeds k, the check fails.  
    5. The 'maxMinHeight' function applies binary search between the minimum element and minimum+k to find the maximum feasible 'mid'.  
    6. Time complexity: \(O(n \cdot \log k)\), since each check runs in \(O(n)\) and binary search iterates over log(k) values.  
    7. Space complexity: \(O(n)\), due to the prefix array used for range updates.  
*/

class Solution {
  public:
      bool check(int mid , vector<int> &arr , int k , int w)    {
        int n = arr.size();
        vector<int>Pref(n + 1 , 0);
        for(int i = 1; i <= n; i++)        {
            int x = arr[i - 1];
            Pref[i] += Pref[i - 1];
            int h = x + Pref[i];
            if(h < mid)            {
                int diff = mid - h;
                if(diff > k)
                    return false;
                Pref[i] += diff;
                if(i + w <= n)
                    Pref[i + w] -= diff;
                    k -= diff;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        int start = *min_element(arr.begin() , arr.end());
        int end = start + k;
        int ans = start;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(check(mid , arr , k , w))
                ans = mid , start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
};

// Key points:
// - The solution uses binary search to maximize the minimum achievable height.
// - The 'check' function simulates water distribution using a prefix difference array for efficiency.
// - Each plant is checked sequentially, and water is added only when necessary.
// - The binary search ensures we find the highest feasible minimum height without exceeding k.
// - Efficient range updates make the algorithm scalable for large inputs.
