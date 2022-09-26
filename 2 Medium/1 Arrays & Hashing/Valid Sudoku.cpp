/*
	Determine if a 9x9 Sudoku board is valid (no repeats)

	Boolean matrices to store seen values. Check rows, cols, 3x3 sub-boxes

	Time: O(cnt^2)
	Space: O(cnt^2)
*/

class Solution
{
    public:
        bool isValidSudoku(vector<vector < char>> &board)
        {
            int N = 9;
            unordered_set<char> row[N];
            unordered_set<char> col[N];
            unordered_set<char> sub[N];

            for (int r = 0; r < N; r++)
            {
                for (int c = 0; c < N; c++)
                {
                    char val = board[r][c];
                    if (val != '.')
                    {
                        int subPos = (r / 3) *3 + c / 3;
                        if (row[r].count(val) || col[c].count(val) || sub[subPos].count(val))
                            return false;
                        row[r].insert(val);
                        col[c].insert(val);
                        sub[subPos].insert(val);
                    }
                }
            }
            return true;
        }
};