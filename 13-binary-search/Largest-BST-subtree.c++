class Solution {
  public:

    int solve(Node* root, int &minVal, int &maxVal, bool &isBST) {

        if (root == nullptr) {
            minVal = INT_MAX;
            maxVal = INT_MIN;
            isBST = true;
            return 0;
        }

        int leftMin, leftMax, rightMin, rightMax;
        bool leftBST, rightBST;

        int leftSize = solve(root->left, leftMin, leftMax, leftBST);
        int rightSize = solve(root->right, rightMin, rightMax, rightBST);

        minVal = min(root->data, leftMin);
        maxVal = max(root->data, rightMax);

        if (leftBST && rightBST && 
           leftMax < root->data &&
           root->data < rightMin) {

            isBST = true;
            return leftSize + rightSize + 1;
        }

        isBST = false;
        return max(leftSize, rightSize);
    }

    int largestBst(Node *root) {
        int minVal, maxVal;
        bool isBST;

        return solve(root, minVal, maxVal, isBST);
    }
};