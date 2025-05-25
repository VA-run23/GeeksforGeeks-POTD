/*
1. First, we create an unordered set 'squares' to store the square of each element for quick lookup.
2. We iterate over the array and insert the square of each number into the set.
3. Next, we use a nested loop to check pairs of numbers in the array.
4. For each pair, we compute their squared sum (i.e., 'a^2 + b^2').
5. We check if this sum exists in the 'squares' set, indicating a valid Pythagorean triplet.
6. If we find a matching triplet, we return 'true' immediately.
7. If no such triplet is found after checking all pairs, we return 'false'.
*/


class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
    
        unordered_set<int> squares;
        for (int num : arr) {
            squares.insert(num * num);
        }

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a2 = arr[i] * arr[i];
                int b2 = arr[j] * arr[j];
                int c2 = a2 + b2;
    
                if (squares.find(c2) != squares.end()) {
                    return true;
                }
            }
        }
    
        return false;
    }
};
