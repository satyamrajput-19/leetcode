class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<bool> res(4, true);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[j][n - 1 - i]) res[0] = false;
                if (mat[i][j] != target[n - 1 - i][n - 1 - j]) res[1] = false;
                if (mat[i][j] != target[n - 1 - j][i]) res[2] = false;
                if (mat[i][j] != target[i][j]) res[3] = false;
            }
        }

        return res[0] || res[1] || res[2] || res[3];
    }
};