/*
Array marking approach:
1. This function finds all numbers missing in the range [low, high] from the given array.
2. It creates a boolean-like vector `vals` of size (high - low + 1) to mark presence of numbers.
3. For each element in `arr`, if it lies within [low, high], mark its position in `vals` as 1.
4. After marking, iterate through `vals` to check which positions remain 0.
5. Each index `i` with value 0 corresponds to the missing number (low + i).
6. Collect these missing numbers into the result vector `ans` and return it.
7. Time Complexity: O(n + (high - low)), Space Complexity: O(high - low + 1).
*/

class SolutionArray {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> vals(high - low + 1, 0), ans;
        for (auto i : arr) {
            if (i >= low && i <= high) vals[i - low] = 1;
        }
        int n = vals.size();
        for (int i = 0; i < n; i++) {
            if (vals[i] == 0) {
                ans.push_back(low + i);
            }
        }
        return ans;
    }
};

// --- Solution 2: Using unordered_set ---
/*
Unordered_set approach:
- Stores only the actual elements of `arr`.
- Average O(1) lookup, but hashing and pointer chasing add overhead.
- More memory-efficient when the range is huge but `arr` is small.
- Time Complexity: O(n + (high - low)), Space Complexity: O(n).
*/

class SolutionSet {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> vals(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (vals.find(i) == vals.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// --- Solution 3: Using unordered_map ---
/*
Unordered_map approach:
- Same hashing overhead as unordered_set, plus unnecessary storage of values.
- Slower because you don’t need the “value” part at all — existence is enough.
- Time Complexity: O(n + (high - low)), Space Complexity: O(n).
*/

class SolutionMap {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_map<int, int> vals;
        for (auto i : arr) {
            vals[i] = 1; // mark presence
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (vals.find(i) == vals.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// --- Comparison ---
// - Array marking (~0.37s): Fastest due to direct indexing and cache-friendly memory,
//   but uses O(high - low + 1) space.
// - Unordered_set (~0.46s): Slightly slower due to hashing overhead, but space-efficient (O(n))
//   when range is huge and arr is sparse.
// - Unordered_map (~0.82s): Slowest, because it stores redundant values; existence-only check
//   is better handled by a set.
// Practical takeaway:
// - If your range size (high - low) is small or moderate → array approach is best (speed).
// - If your range size is very large and arr is sparse → unordered_set is better (space).
// - Unordered_map is simply redundant here — it does what unordered_set already does, but slower.
