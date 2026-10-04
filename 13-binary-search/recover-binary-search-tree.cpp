/**
 * LeetCode 99 - Recover Binary Search Tree
 *
 * Approach:
 * 1. Perform inorder traversal of the BST.
 * 2. A valid BST has sorted inorder values.
 * 3. Find the two nodes where the sorted order is violated.
 * 4. Swap their values to recover the BST.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:

    // Store nodes in inorder: smallest -> largest
    void inOrder(TreeNode* root, vector<TreeNode*>& arr) {

        if (root == nullptr)
            return;

        inOrder(root->left, arr);

        arr.push_back(root);

        inOrder(root->right, arr);
    }

    void recoverTree(TreeNode* root) {

        vector<TreeNode*> arr;

        // Store all nodes in inorder order
        inOrder(root, arr);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Find the two swapped nodes
        for (int i = 1; i < arr.size(); i++) {

            if (arr[i - 1]->val > arr[i]->val) {

                // First violation
                if (first == nullptr) {
                    first = arr[i - 1];
                    second = arr[i];
                }
                // Second violation
                else {
                    second = arr[i];
                }
            }
        }

        // Swap the values of the two incorrect nodes
        int val = first->val;
        first->val = second->val;
        second->val = val;
    }
};