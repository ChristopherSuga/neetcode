/*
    Search for target value in matrix where every row & col is sorted

    Perform 2 binary searches: 1 to find row, then another to find col

    Time: O(log m + log n)
    Space: O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowRow = 0;
        int highRow = matrix.size() - 1;

        //binary search on the rows
        while (lowRow < highRow) {
            int mid = lowRow + (highRow - lowRow) / 2;
            //base case for if the target is the first number we check
            if (matrix[mid][0] == target) {
                return true;
            }
            //if the target is in the current row being checked saves the current row
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                lowRow = mid;
                break;
            }
            //if the the beginning number of the current row is less than the target moves the low row pointer
            if (matrix[mid][0] < target) {
                lowRow = mid + 1;
            }
            //if it is bigger moves the high row pointer
            else {
                highRow = mid - 1;
            }
        }

        int lowCol = 0;
        int highCol = matrix[0].size() - 1;
        //regular binary search on the column
        while (lowCol <= highCol) {
            int mid = lowCol + (highCol - lowCol) / 2;
            if (matrix[lowRow][mid] == target) {
                return true;
            }
            if (matrix[lowRow][mid] < target) {
                lowCol = mid + 1;
            }
            else {
                highCol = mid - 1;
            }
        }

        return false;
    }
};