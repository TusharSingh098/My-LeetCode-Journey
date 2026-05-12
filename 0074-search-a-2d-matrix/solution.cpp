class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();

        int low{0}, high = matrix.size() * n - 1;
        
        while (low <= high)
        {
            int mid{low + (high - low) / 2};

            int val{matrix[mid / n][mid % n]};

            if (val > target) high = mid - 1;
            else if (val < target) low = mid + 1;
            else return true;
        }
        return false;
    }
};
