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
    unordered_map<int,vector<int> > m;
    int maxi=0;
    void dfs(TreeNode* root,int l)
    {
        if(root==NULL)
            return;

        m[l].push_back(root->val);
        ++l;
        maxi=max(maxi,l);
        dfs(root->left,l);
        dfs(root->right,l);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int> > f;
        dfs(root,0);
        for(int i=0;i<maxi;i++)
        {
            f.push_back(m[i]);
        }
       reverse(f.begin(),f.end());
        cout << maxi;
        return f;
    }
};
