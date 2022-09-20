/*
	Determine if a 9x9 Sudoku board is valid (no repeats)

	Boolean matrices to store seen values. Check rows, cols, 3x3 sub-boxes

	Time: O(cnt^2)
	Space: O(cnt^2)
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector < char>>& board)
    {
        const int cnt = 9;
        //bool matrices for the rows columns and subsquares
        //rows represent row col and subsquares
        //columns represent the numbers 1-9
        bool row[cnt][cnt] = { false
        };
        bool col[cnt][cnt] = { false
        };
        bool sub[cnt][cnt] = { false
        };
        //nested for loop to iterate over the board
        for (int r = 0; r < cnt; ++r)
        {
            for (int c = 0; c < cnt; ++c)
            {
                //if the value is not a period then it means it is a number and enters the block
                if (board[r][c] != '.')
                {
                    //char to num idx the -1 is there because the matrix includes 0 but sudoku is 1-9
                    int idx = board[r][c] - '0' - 1;
                    //area calculates what subsquare we are in
                    int area = (r / 3) * 3 + (c / 3);
                    //if the value already exists in the row column or subsquare then returns false
                    if (row[r][idx] || col[c][idx] || sub[area][idx])
                    {
                        return false;
                    }
                    //if the value doesnt exist then it adds it to their respective location
                    row[r][idx] = true;
                    col[c][idx] = true;
                    sub[area][idx] = true;
                }
            }
        }
        return true;
    }
};