/**
 * LeetCode 98 - Validate Binary Search Tree
 *
 * Approach:
 * Use recursion with a valid range [low, high].
 *
 * For every node:
 * 1. The node value must be strictly between low and high.
 * 2. Left subtree gets the range [low, node->val].
 * 3. Right subtree gets the range [node->val, high].
 *
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */

class Solution {
public:

    bool solve(TreeNode* node, long low, long high) {

        if (node == nullptr)
            return true;

        int value = node->val;

        // BST requires strictly: low < value < high
        if (value >= high || value <= low)
            return false;

        bool left = solve(node->left, low, value);
        bool right = solve(node->right, value, high);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return solve(root, LONG_MIN, LONG_MAX);
    }
};