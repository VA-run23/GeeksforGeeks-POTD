/*
    1. This algorithm aims to find the maximum minimum height we can achieve for the array 'arr' by adding at most 'k' total units, where updates affect a sliding window of width 'w'.
    2. A binary search is performed on the possible answer space (between min element and min + k), checking feasibility of each candidate height 'mid'.
    3. The 'check' function uses a prefix sum difference array (range addition technique) to simulate increasing heights efficiently within window size 'w'.
    4. If the current height 'x + Pref[i]' is less than 'mid', it computes the 'diff' and adds it to the prefix array, subtracting it after 'w' to simulate range update.
    5. If at any point required units exceed available 'k', the current mid is invalid, so binary search adjusts accordingly.
    6. The approach efficiently balances simulation accuracy with performance, handling cumulative updates without modifying the original array each time.
    7. Time complexity: O(n log k), Space complexity: O(n) — where n is the array size and log k comes from the binary search range.
*/

class Solution {
  public:
  
    bool check(int mid , vector<int> &arr , int k , int w)
    {
        int n = arr.size();
        vector<int>Pref(n + 1 , 0);
        for(int i = 1; i <= n; i++)
        {
            int x = arr[i - 1];
            Pref[i] += Pref[i - 1];
            int h = x + Pref[i];
            if(h < mid)
            {
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
  
    int maxMinHeight(vector<int> &arr, int k, int w) 
    {
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