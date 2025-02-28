class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> s;

        for (string& elem : arr) {
            if (elem == "+" || elem == "-" || elem == "*" || elem == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (elem == "+") s.push(a + b);
                else if (elem == "-") s.push(a - b);
                else if (elem == "*") s.push(a * b);
                else if (elem == "/") s.push(a / b);
            } else {
                s.push(stoi(elem));
            }
        }

        return s.top();
    }
};