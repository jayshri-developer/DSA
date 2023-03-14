// Approach 1
// PL:- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// TC:- O(n)
// SC:- O(n)


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left && right)
        {
            return root;
        }

        if(left != NULL)
        {
            return left;
        }

        return right;
    }
};
