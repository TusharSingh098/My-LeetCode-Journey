class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pscl_trngl;
        for (int i{0}; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j{1}; j < i; j++)
            {
                row[j] = pscl_trngl[i - 1][j - 1] + pscl_trngl[i - 1][j];
            }
            pscl_trngl.emplace_back(row);
        }
        return pscl_trngl;
    }
};
