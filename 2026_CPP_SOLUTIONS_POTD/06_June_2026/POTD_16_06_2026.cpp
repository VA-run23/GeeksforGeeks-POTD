// Construct List using XOR Queries

/*
 *    1. The problem involves processing XOR-based queries on a list.
 *    2. Queries of type 1 apply XOR to all future elements.
 *    3. Queries of type 2 insert an element into the list.
 *    4. To handle efficiently, we track cumulative XOR from the end.
 *    5. Each insertion is adjusted with the current XOR value.
 *    6. Finally, include the XOR effect on 0 and sort the list.
 *    7. Time Complexity: O(q log q), Space Complexity: O(q)
 */

class Solution {
    public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int> result;
        int currXOR = 0;
        int q = queries.size();
        
        for (int i = q - 1; i >= 0; i--) {
            if (queries[i][0] == 1) {
                currXOR ^= queries[i][1];
            } else {
                result.push_back(queries[i][1] ^ currXOR);
            }
        }
        
        result.push_back(0 ^ currXOR);
        sort(result.begin(), result.end());
        return result;
    }
};

// Key Points
// 1. XOR operations are cumulative and reversible.
// 2. Traversing queries backward simplifies handling type 1.
// 3. Insertions are adjusted with current XOR state.
// 4. Adding 0 ensures XOR effect is fully captured.
// 5. Sorting final list gives required output order.
// 6. Efficient use of XOR avoids repeated recomputation.
// 7. Overall solution balances simplicity and performance.