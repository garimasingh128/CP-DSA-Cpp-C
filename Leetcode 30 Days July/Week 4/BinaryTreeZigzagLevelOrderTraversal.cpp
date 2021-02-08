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
    int maxi=-1;
    void dfs(TreeNode* root,int l)
    {
        if(root==NULL)
            return;

        m[l].push_back(root->val);

        l++;
        dfs(root->left,l);
        dfs(root->right,l);
        maxi=max(maxi,l);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


        vector<vector<int> > f;
        vector<int> t;
        int i;
        dfs(root,0);

        for(i=0;i<maxi;i++)
        {
            t=m.at(i);
            if(i&1)
                reverse(t.begin(),t.end());
            f.push_back(t);
        }
        return f;

    }
};
