class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;

            for(int j = 0; j < 9; j++) {
                //check row
                if(board[i][j] != '.') {
                    if(rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }

                //check col
                if(board[j][i] != '.') {
                    if(colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        unordered_map<int, unordered_set<char>> sqr;

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;

                int box = (i / 3) * 3 + (j / 3);

                if(sqr[box].count(board[i][j])) return false;

                sqr[box].insert(board[i][j]);
            }
        }

        return true;
    }
};
