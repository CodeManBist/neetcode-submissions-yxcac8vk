class Solution {
public:
    bool search(int n, int m, int i, int j, vector<vector<char>>& board, string& word, int k) {
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k]) return false;
        
        char ch = board[i][j];
        board[i][j] = '#';

        bool option1 = search(n, m, i + 1, j, board, word, k+1);
        bool option2 = search(n, m, i - 1, j, board, word, k+1);
        bool option3 = search(n, m, i, j + 1, board, word, k+1);
        bool option4 = search(n, m, i, j - 1, board, word, k+1);

       board[i][j] = ch;

        return option1 || option2 || option3 || option3 || option4;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    if(search(rows, cols, i, j, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};
