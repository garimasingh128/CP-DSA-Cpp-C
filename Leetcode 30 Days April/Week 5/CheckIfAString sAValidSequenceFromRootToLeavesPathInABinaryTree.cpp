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
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {

        if(!root)
            return arr.size()==0;
        else
            return isvalid(root,arr,0);
    }
    bool isvalid(TreeNode* root, vector<int>& arr,int i)
    {
        if(root->val!=arr[i])
            return false;
        if(i==arr.size()-1)
            return !root->left && !root->right;
        return ((root->left &&  isvalid(root->left,arr,i+1)) || (root->right &&  isvalid(root->right,arr,i+1)));
    }
};
