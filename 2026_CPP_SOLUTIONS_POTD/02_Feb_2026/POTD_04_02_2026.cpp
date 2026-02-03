/*
    1. The problem asks for the last moment before all ants fall off a plank of length n.
    2. Ants move left or right at speed 1; when they meet, they swap directions but this is equivalent to them continuing unaffected.
    3. This equivalence means we can ignore collisions entirely and just compute each ant’s fall time.
    4. For left-moving ants, fall time = position (distance to 0).
    5. For right-moving ants, fall time = n - position (distance to end).
    6. The solution finds the maximum of these times across all ants to get the last fall moment.
    7. Time Complexity: O(p + q), Space Complexity: O(1), making it optimal and elegant.
*/
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int ans = 0, p = left.size(), q = right.size();
        for(int i = 0; i<p; i++){
            ans = max(ans, left[i]);
        }
        for(int i = 0; i<q;i++){
            ans = max(ans, n - right[i]);
        }
        return ans;
    }
};

/* Key points:
- Collisions are irrelevant because swapping directions is indistinguishable from ants passing through each other.
- This insight reduces the problem to a simple max-distance calculation.
- Left ants contribute their position as fall time; right ants contribute (n - position).
- The maximum of these values gives the last fall moment.
- The elegance lies in transforming a seemingly complex simulation into a direct mathematical observation.
- The algorithm is optimal: linear scan, constant space, no extra data structures.
- It works because the "collision equivalence" ensures correctness without simulating movements.
*/
