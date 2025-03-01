//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> B;
        stack<int> num;
        string ans = "";
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                num.push(count);
            } else if (s[i] == '[') {
                B.push(ans);
                ans = "";
                i++;
            } else if (s[i] == ']') {
                string temp = B.top();
                B.pop();
                int count = num.top();
                num.pop();
                
                for (int j = 0; j < count; j++) {
                    temp += ans;
                }
                ans = temp;
                i++;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends