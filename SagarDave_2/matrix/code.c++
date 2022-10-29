class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& M) {
        int y = M.size(), x = M[0].size() - 1;
        vector<int> diag(y);
        for (int i = 2 - y; i < x; i++) {
            int k = 0;
            for (int j = 0; j < y; j++)
                if (i+j >= 0 && i+j <= x) {
                    diag[k] = M[j][i+j];
                    k++;
                }
            sort(diag.begin(), diag.begin() + k);
            k = 0;
            for (int j = 0; j < y; j++)
                if (i+j >= 0 && i+j <= x) {
                    M[j][i+j] = diag[k];
                    k++;
                }
        }
        return M;
    }
};