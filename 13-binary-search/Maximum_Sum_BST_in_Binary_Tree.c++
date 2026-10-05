class Solution {
public:

    int ans = 0;

    struct Info {
        bool isBst;
        int sum;
        int minVal;
        int maxVal;
    };

    Info solve(TreeNode* root) {

        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.isBst &&
            right.isBst &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;

            ans = max(ans, sum);

            return {
                true,
                sum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }

        return {
            false,
            0,
            INT_MIN,
            INT_MAX
        };
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};