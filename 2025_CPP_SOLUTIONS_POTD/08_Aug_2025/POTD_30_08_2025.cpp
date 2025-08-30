/*
    1. Initialize a vector of pairs 'celeb' to track each person's outdegree (knows others) and indegree (known by others).
    2. Loop through the matrix and skip self-relations ('i == j') since they don't affect celebrity status.
    3. If person 'i' knows person 'j', increment 'i''s outdegree and 'j''s indegree.
    4. After populating degrees, loop through each person to check if they know no one ('outdegree == 0')
        and are known by everyone else ('indegree == n - 1').
    5. If such a person is found, return their index as the celebrity.
    6. If no one satisfies both conditions, return -1 indicating no celebrity exists.
    7. Time Complexity: O(n²) due to nested loops; Space Complexity: O(n) for the 'celeb' vector.
*/

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<pair<int, int>> celeb(n, {0, 0}); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j ) continue;
                if(mat[i][j]){
                    celeb[i].first++;   
                    celeb[j].second++;  
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(celeb[i].first == 0 && celeb[i].second == n - 1){
                return i; 
            }
        }

        return -1; 
    }
};