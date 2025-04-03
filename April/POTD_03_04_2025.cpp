/*
    1. Initialize dimensions n & m, track rotten oranges' positions, count fresh oranges, and set time to 0.
    2. Traverse the grid to populate rotten positions and count fresh oranges.
    3. Start the rotting process using a loop while there are rotten oranges and fresh ones still exist.
    4. Create newRotten to store oranges that turn rotten in this cycle.
    5. Check all four directions (up, down, left, right); if a fresh orange is adjacent, mark it rotten, decrement fresh, and add it to newRotten.
    6. Replace rotten with newRotten and increment time after each cycle.
    7. If all fresh oranges are rotten, return time; otherwise, return -1 indicating some remained fresh.
*/

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> rotten;
        int fresh = 0, time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) rotten.push_back(make_pair(i, j));
                else if (mat[i][j] == 1) fresh++;
            }
        }

        while (!rotten.empty() && fresh > 0) {
            vector<pair<int, int>> newRotten;
            for (int i = 0; i < rotten.size(); i++) {
                int x = rotten[i].first;
                int y = rotten[i].second;

                if (x > 0 && mat[x-1][y] == 1) { mat[x-1][y] = 2; fresh--; newRotten.push_back(make_pair(x-1, y)); }
                if (x < n-1 && mat[x+1][y] == 1) { mat[x+1][y] = 2; fresh--; newRotten.push_back(make_pair(x+1, y)); }
                if (y > 0 && mat[x][y-1] == 1) { mat[x][y-1] = 2; fresh--; newRotten.push_back(make_pair(x, y-1)); }
                if (y < m-1 && mat[x][y+1] == 1) { mat[x][y+1] = 2; fresh--; newRotten.push_back(make_pair(x, y+1)); }
            }
            rotten = newRotten;
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};