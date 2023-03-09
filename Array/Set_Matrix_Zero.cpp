
// BruteForce: Can be done by using -1 as marking if all the values are not
// negative. time complexity- O(n*m) + O(n+m)

// Better way: can be implemented by using two arrays one to handle row wise
// marking and another for column wise marking

// Best way : can be doing marking on the same matrix first row and first
// column, then just follow the other process

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool rowFlg = false, colFlg = false;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (i == 0 and matrix[i][j] == 0)
          rowFlg = true;
        if (j == 0 and matrix[i][j] == 0)
          colFlg = true;
        if (matrix[i][j] == 0) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][0] == 0 or matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (rowFlg) {
      for (int j = 0; j < col; j++)
        matrix[0][j] = 0;
    }
    if (colFlg) {
      for (int i = 0; i < row; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};