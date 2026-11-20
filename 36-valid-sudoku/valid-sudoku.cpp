class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> r[9];
        unordered_set<char> c[9];
        unordered_set<char> g[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int ind = (i / 3) * 3 + (j / 3);

                if (r[i].count(board[i][j]) || c[j].count(board[i][j]) || g[ind].count(board[i][j])) {
                    return false;
                }

                r[i].insert(board[i][j]);
                c[j].insert(board[i][j]);
                g[ind].insert(board[i][j]);
            }
        }

        return true;
    }
};