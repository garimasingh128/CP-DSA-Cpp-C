/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_value = INT_MAX)
    {
        if (idx == preorder.size() || preorder[idx] > parent_value)
            return NULL;
        int current_value = preorder[idx++];
        TreeNode *temp = new TreeNode(current_value);
        temp->left = bstFromPreorder(preorder, current_value);
        temp->right = bstFromPreorder(preorder, parent_value);
        return temp;
    }
};
