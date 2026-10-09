class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int j{1}; j < rowIndex; j++) {
            row[j] = (int)((row[j - 1] * (rowIndex - j + 1LL)) / j);
        }

        return row;
    }
};