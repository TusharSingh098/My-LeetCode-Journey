class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isFirstRowZero{false}, isFirstColZero{false};
        
        for (int i{0}; i < matrix.size(); i++)
        {
            for (int j{0}; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0) isFirstRowZero = true;
                    if (j == 0) isFirstColZero = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i{1}; i < matrix.size(); i++)
        {
            for (int j{1}; j < matrix[i].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (isFirstRowZero)
        {
            for (int j{0}; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
        if (isFirstColZero)
        {
            for (int i{0}; i < matrix.size(); i++) matrix[i][0] = 0;
        }
    }
};
