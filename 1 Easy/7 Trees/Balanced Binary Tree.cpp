/*
    Given binary tree, determine if height-balanced (all left & right subtrees height diff <= 1)

    Check if subtrees are balanced, if so, use their heights to determine further balance

    Time: O(n)
    Space: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
private:
    bool dfs(TreeNode* root, int& height) {
        //base case for if root is null
        if (root == NULL) {
            height = -1;
            return true;
        }

        int leftHeight = 0;
        int rightHeight = 0;
        //if the recursive call ever returns a
        if (!dfs(root->left, leftHeight) || !dfs(root->right, rightHeight)) {
            return false;
        }
        //returns false if the height is un-balanced
        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};