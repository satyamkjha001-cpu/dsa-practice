/**
 * LeetCode 114 - Flatten Binary Tree to Linked List
 *
 * Approach:
 * Morris-style traversal
 *
 * For every node:
 * 1. If the node has a left subtree, find the rightmost node
 *    of that left subtree.
 * 2. Connect that rightmost node to the current node's right subtree.
 * 3. Move the left subtree to the right.
 * 4. Set the left pointer to nullptr.
 * 5. Move to the next node through the right pointer.
 *
 * The resulting tree becomes a right-skewed linked list
 * following preorder traversal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * LeetCode: 114
 */

class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        while (curr) {

            if (curr->left) {

                // Find the rightmost node of the left subtree.
                TreeNode* pred = curr->left;

                while (pred->right) {
                    pred = pred->right;
                }

                // Connect the right subtree after the left subtree.
                pred->right = curr->right;

                // Move the left subtree to the right.
                curr->right = curr->left;

                // Remove the left child.
                curr->left = nullptr;
            }

            // Move to the next node.
            curr = curr->right;
        }
    }
};