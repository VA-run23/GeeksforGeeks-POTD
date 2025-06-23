/*
    1. The goal is to form two numbers from the given digits such that their sum is minimized, and return the minimum sum as a string.
    2. The function 'isPossible' simulates adding digits to two numbers (initially 0) by always appending the next digit to the smaller current number.
    3. This greedy construction ensures digits are balanced across the two numbers to keep their sum minimal.
    4. In 'minSum', the digits are first sorted to ensure smallest digits are placed first, maximizing their weight efficiency.
    5. Binary search is applied over a large numeric range [0, 1e12] to find the minimum valid sum satisfying the 'isPossible' condition.
    6. The smallest such 'mid' where 'isPossible' is true is stored in 'ans', and returned as a string with no leading zeroes.
    7. Time complexity is O(N log N + log(1e12) * N), and space complexity is O(N) due to sorting and heap operations.
*/

class Solution {
public:
    bool isPossible(vector<int>& arr, long long mid) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(0);
        pq.push(0);
        
        for (int digit : arr) {
            long long smallest = pq.top();
            pq.pop();
            smallest = smallest * 10 + digit;
            pq.push(smallest);
        }
        
        long long num1 = pq.top(); pq.pop();
        long long num2 = pq.top();
        
        return num1 + num2 <= mid;
    }
    
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        long long low = 0, high = 1e12, ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isPossible(arr, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return to_string(ans);
    }
};