class Solution {
    public:
        TreeNode *upsideDownBinaryTree(TreeNode *root) {
            TreeNode *temp, *newRoot = NULL;
            temp = buildUpsideDownBT(root, newRoot);
            return newRoot;
        }

        TreeNode *buildUpsideDownBT(TreeNode *root, TreeNode *&newRoot) {
            if(!root) return root;
            if(!root->left && !root->right) {
                newRoot = root;
                return root;
            }
            TreeNode *parent = buildUpsideDownBT(root->left, newRoot);
            parent->left = root->right;
            parent->right = root;
            root->left = root->right = NULL;
            return parent->right;
        }
};
