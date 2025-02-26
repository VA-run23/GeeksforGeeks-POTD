class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> mp;
        for (string& str : arr) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& p : mp) {
            result.push_back(p.second);
        }
        return result;
    }
};

///////EXPLANATION:

//     string s = "adabsdASD";
//     cout << s << endl;
//     sort(s.begin(), s.end());
//     cout << s << endl;


//////OUTPUT:
// //adabsdASD
// // ADSaabdds