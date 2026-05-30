class Solution {
private:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans,vector<bool>& lR, vector<bool>& lD, vector<bool>& uD)
    {
        if (col == n)
        {
            ans.emplace_back(board);
            return;
        }

        for (int row{0}; row < n; row++)
        {
            int uDIdx{row + col}, lDIdx{row - col + (n - 1)};

            if (!lR[row] && !uD[uDIdx] && !lD[lDIdx])
            {
                board[row][col] = 'Q';
                lR[row] = true;
                uD[uDIdx] = true;
                lD[lDIdx] = true;

                solve(col + 1, n, board, ans, lR, lD, uD);
                
                board[row][col] = '.';
                lR[row] = false;
                uD[uDIdx] = false;
                lD[lDIdx] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> leftR(n, false), lowerD(2 * n - 1, false), upperD(2 * n - 1, false);

        solve(0, n, board, ans, leftR, lowerD, upperD);
        return ans;
    }
};