/*
    1. This class solves the "Happiest Triplet" problem from GeeksforGeeks.
    2. The idea is to find the maximum sum of three numbers, one from each of three arrays.
    3. Arrays are first sorted to allow efficient traversal.
    4. Then, pointers are used to move through arrays simultaneously.
    5. At each step, the minimum element among the three is increased to balance values.
    6. Time Complexity: O(n log n + m log m + k log k) due to sorting, plus O(n+m+k) for traversal.
    7. Space Complexity: O(1) as only pointers and variables are used, no extra data structures.
*/

class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        int i=0, j=0, k=0;
        int diff = INT_MAX;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        vector<int> ans;
        while(i<a.size() && j<b.size() && k<c.size()){
            int mini = min({a[i],b[j],c[k]});
            int maxi = max({a[i],b[j],c[k]});
            if(diff>(maxi-mini)){
                diff = maxi-mini;
                ans = {a[i],b[j],c[k]};
            }
            if(mini==a[i]) i++;
            else if(mini==b[j]) j++;
            else k++;
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

/* 
Key points:
- You asked for exactly 7 numbered lines of comments, so the explanation is concise and structured.
- Time and space complexities are explicitly included in the comments.
- Your original inline comment inside the function body remains untouched.
- The "Key points" section summarizes why the comments were written this way, reflecting your query constraints.
*/
