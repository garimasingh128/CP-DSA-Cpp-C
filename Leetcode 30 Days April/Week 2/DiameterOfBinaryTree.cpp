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
    int maxi=-1;
    int rec(TreeNode* root)
    {
        if(!root)
            return 0;
        if(!root->right && !root->left)
            return 0;
        int rmax=0;
        int lmax=0;
        if(root->right)
            rmax=1+rec(root->right);
        if(root->left)
            lmax=1+rec(root->left);
        maxi=max(maxi,lmax+rmax);
        return max(lmax,rmax);


    }
    int diameterOfBinaryTree(TreeNode* root) {

        return max(maxi,rec(root));
    }
};
