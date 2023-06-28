

// dfs solution

class Solution {
public:
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};

    void dfs(int sr, int sc, int n, int m, vector<vector<int>> &image2,
             int newColor, int initColor) {
        image2[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int calRow = sr + di[i];
            int calCol = sc + dj[i];
            if (calRow >= 0 and calRow < n and calCol >= 0 and calCol < m and
                image2[calRow][calCol] == initColor and
                image2[calRow][calCol] != newColor) {
                dfs(calRow, calCol, n, m, image2, newColor, initColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size();

        vector<vector<int>> image2 = image;

        int initColor = image[sr][sc];
        dfs(sr, sc, n, m, image2, newColor, initColor);
        return image2;
    }
};

// time complexity : O(n^2)
// space complexity : O(n^2)