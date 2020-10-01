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
    int widthOfBinaryTree(TreeNode* root) {

        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int> > q;
        int i,c,s;
        q.push({root,1});
        int maxi=1;
        while(!q.empty())
        {
            c=q.size();
            maxi=max(maxi,q.back().second-q.front().second+1);
            s=q.front().second;
            for(i=0;i<c;i++)
            {
                pair<TreeNode*,int> t=q.front();


                if(t.first->left)
                    q.push({t.first->left,(t.second-s)*2+1});
                if(t.first->right)
                    q.push({t.first->right,(t.second-s)*2+2});

                q.pop();
            }



        }
        return maxi;
    }
};
