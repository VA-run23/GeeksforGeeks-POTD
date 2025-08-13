
/*
The correct approach:

    1. The problem requires at least ⌈n/2⌉ troops to be "lucky" — meaning their soldier count is divisible by k.
    2. Some troops may already be lucky and require zero additional soldiers.
    3. If we blindly sum the smallest ⌈n/2⌉ values from the cost array, we risk including troops that are already lucky.
    4. This leads to overestimating the total number of soldiers needed, as we may fix more troops than necessary.
    5. To avoid this, we must first count how many troops are already lucky.
    6. Then, we only need to fix the remaining number of unlucky troops to meet the ⌈n/2⌉ lucky troop requirement.
    7. This adjustment ensures the solution is both correct and optimal, avoiding unnecessary additions.
*/

class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int luckyTroopsNeeded = (n + 1) / 2;

        vector<int> costs;
        int alreadyLucky = 0;

        for (int i = 0; i < n; i++) {
            int cost = (k - arr[i] % k) % k;
            if (cost == 0) {
                alreadyLucky++;
            } else {
                costs.push_back(cost);
            }
        }

        int toFix = max(0, luckyTroopsNeeded - alreadyLucky);
        sort(costs.begin(), costs.end());

        int totalSoldiers = accumulate(costs.begin(), costs.begin() + toFix, 0);
        return totalSoldiers;
    }
};