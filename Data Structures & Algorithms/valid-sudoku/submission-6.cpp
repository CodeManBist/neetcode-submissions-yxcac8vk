class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            unordered_set<char> s1;

            for(int j = 0; j < m; j++) {
                if(board[i][j] != '.') {
                    if(s1.find(board[i][j]) != s1.end()) {
                        return false;
                    }
                    s1.insert(board[i][j]);
                }
            }  
        }

        for(int i = 0; i < m; i++) {
            unordered_set<char> s2;

            for(int j = 0; j < n; j++) {
                if(board[j][i] != '.') {
                    if(s2.find(board[j][i]) != s2.end()) {
                        return false;
                    }
                    s2.insert(board[j][i]);
                }
            }  
        }

        for(int row = 0; row < 9; row += 3) {
            for(int col = 0; col < 9; col += 3) {
                unordered_set<char> st;
                for(int i = row; i < row + 3; i++) {
                    for(int j = col; j < col + 3; j++) {
                        if(board[i][j] != '.' ) {
                            if(st.find(board[i][j]) != st.end()) {
                                return false;
                            }

                            st.insert(board[i][j]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
