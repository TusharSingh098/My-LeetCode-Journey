class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for (int i{0}; i < 9; i++)
        {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int pos)
    {
        if (pos == 81) return true;

        int row{pos / 9}, col{pos % 9};

        if (board[row][col] != '.') return solve(board, pos + 1);

        for (char c{'1'}; c <= '9'; c++)
        {
            if (isValid(board, row, col, c))
            {
                board[row][col] = c;
                if (solve(board, pos)) return true;
                else board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
};