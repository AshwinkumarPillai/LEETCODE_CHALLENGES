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
class Solution
{
public:
    int good = 0;
    void countMax(TreeNode *root, int m)
    {
        if (root->val >= m)
        {
            good++;
        }
        int big = max(root->val, m);
        if (root->left == NULL && root->right == NULL)
        {
            return;
        }
        else
        {
            if (root->left == NULL)
            {
                return countMax(root->right, big);
            }
            else if (root->right == NULL)
            {
                return countMax(root->left, big);
            }
            else
            {
                countMax(root->left, big);
                countMax(root->right, big);
                return;
            }
        }
    }
    int goodNodes(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        countMax(root, root->val);
        return good;
    }
};