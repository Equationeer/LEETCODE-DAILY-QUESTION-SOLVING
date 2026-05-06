class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();
        vector<vector<char>> rotate(col, vector<char>(row, '.'));
        for (int k = 0; k < row; k++) {
            int bottom = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (boxGrid[k][j] == '#') {
                    rotate[bottom][row - 1 - k] = '#';
                    bottom--;
                } 
                else if (boxGrid[k][j] == '*') {
                    rotate[j][row - 1 - k] = '*';
                    bottom = j - 1;
                }
            }
        }
        return rotate;
    }
};