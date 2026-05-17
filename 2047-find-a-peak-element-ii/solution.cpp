class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (m == 1 && n == 1) return {0,0};

        int low{0}, high{n - 1};
        while (low <= high)
        {
            int mid{low + (high - low) / 2};
            
            int maxR{0};
            for (int i{0}; i < m; i++)
            {
                if (mat[i][mid] > mat[maxR][mid]) maxR = i;
            }

            int leftVal = (mid > 0) ? mat[maxR][mid - 1] : -1;
            int rightVal = (mid < n - 1) ? mat[maxR][mid + 1] : -1;
            
            if (mat[maxR][mid] > leftVal 
                    && mat[maxR][mid] > rightVal)
                        return {maxR, mid};

            else if (mat[maxR][mid] < leftVal ) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};
