/*
    1. The floodFill function starts by storing the original color of the starting pixel.
    2. It calls dfs, a recursive function, to change connected pixels that share the original color.
    3. The dfs function ensures pixels are within bounds and not already processed before updating.
    4. If valid, the pixel’s color is changed, and recursion continues in four directions (up, down, left, right).
    5. This ensures all adjacent pixels of the same original color are updated properly.
    6. Time Complexity: O(N), where N is the total number of pixels in the image (each pixel is visited once).
    7. Space Complexity: O(N) in the worst case (when recursion goes as deep as the number of pixels).
*/

class Solution {
    public:
      void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int originalColor) {
          if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || 
              image[sr][sc] != originalColor || image[sr][sc] == newColor) {
              return;
          }
          
          image[sr][sc] = newColor;
          
          dfs(image, sr + 1, sc, newColor, originalColor);
          dfs(image, sr - 1, sc, newColor, originalColor);
          dfs(image, sr, sc + 1, newColor, originalColor);
          dfs(image, sr, sc - 1, newColor, originalColor);
      }
      
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
          // Code here
          int originalColor = image[sr][sc];
          dfs(image, sr, sc, newColor, originalColor);
          return image;
      }
  };