class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int j{n - 1};

        for (int i{0}; i < m; i++)
        {
            while (j >= 0 && matrix[i][j] > target) j--;
            if (j >= 0 && matrix[i][j] == target) return true;
        }
        return false;
    }
};
