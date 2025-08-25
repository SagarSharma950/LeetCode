class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        vector<vector<int>> diagonals(m + n - 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }
        for (int d = 0; d < diagonals.size(); ++d) {
            if (d % 2 == 0) {
                result.insert(result.end(), diagonals[d].rbegin(), diagonals[d].rend());
            } else {
                result.insert(result.end(), diagonals[d].begin(), diagonals[d].end());
            }
        }
        return result;
    }
};