class Solution {
public:
    int f=0;
    void add(TreeNode* root,string s)
    {
        if(root->left==NULL &&  root->right==NULL)
        {
            s+=to_string(root->val);
            f+=stoi(s);
            return;
        }
        else if(root->left==NULL &&  root->right!=NULL)
            add(root->right,s+to_string(root->val));
        else if(root->left!=NULL &&  root->right==NULL)
             add(root->left,s+to_string(root->val));
        else
        {
            add(root->left,s+to_string(root->val));
            add(root->right,s+to_string(root->val));
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        add(root,"");
        return f;
    }
};
