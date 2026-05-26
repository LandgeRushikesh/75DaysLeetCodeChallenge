class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, 
             int originalColor, int newColor) {
        
        int m = image.size();
        int n = image[0].size();

        // Base conditions
        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        if (image[r][c] != originalColor)
            return;

        // Change color
        image[r][c] = newColor;

        // Visit 4 directions
        dfs(image, r - 1, c, originalColor, newColor); // up
        dfs(image, r + 1, c, originalColor, newColor); // down
        dfs(image, r, c - 1, originalColor, newColor); // left
        dfs(image, r, c + 1, originalColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, int sc, int color) {
        
        int originalColor = image[sr][sc];

        // Important edge case
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color);

        return image;
    }

};