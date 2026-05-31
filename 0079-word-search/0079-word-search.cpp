class Solution {
private:
    bool solve(vector<vector<char>>& board, const string& word, int row, int col, int idx)
    {
        if (board[row][col] != word[idx]) return false;

        if (idx == word.length() - 1) return true;

        char letter{board[row][col]};
        board[row][col] = '*';

        if (row > 0 && board[row - 1][col] == word[idx + 1] && solve(board, word, row - 1, col, idx + 1)) return true;
        if (row < board.size() - 1 && board[row + 1][col] == word[idx + 1] && solve(board, word, row + 1, col, idx + 1)) return true;
        if (col > 0 && board[row][col - 1] == word[idx + 1] && solve(board, word, row, col - 1, idx + 1)) return true;
        if (col < board[0].size() - 1 && board[row][col + 1] == word[idx + 1] && solve(board, word, row, col + 1, idx + 1)) return true;

        board[row][col] = letter;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();

        int bFreq[128] = {0}, wFreq[128] = {0};
        for (int i{0}; i < row; i++) for (int j{0}; j < col; j++) bFreq[board[i][j]]++;
        for (char ch: word) wFreq[ch]++;

        for (int i{65}; i < 123; i++) if (bFreq[i] < wFreq[i]) return false;

        if (bFreq[word.back()] < bFreq[word[0]]) 
        {
            reverse(word.begin(), word.end());
        }

        for (int i{0}; i < row; i++)
        {
            for (int j{0}; j < col; j++)
            {
                if (solve(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};