class Solution {
public:
    void preorder(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        if(root->left)
            preorder(root->left, ans);
        if(root->right)
            preorder(root->right, ans);
    }

    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        vector<int> ans;
        preorder(root, ans);

        root->left = NULL;
        TreeNode* curr = root;
        TreeNode* pre_curr = new TreeNode();
        pre_curr->right = curr;

        int i=0;
        while(curr)
        {
            curr->val = ans[i];
            curr->left = NULL;
            pre_curr = curr;
            curr = curr->right;
            i++;
        }
        while(i<ans.size())
        {            
            TreeNode* nextnode = new TreeNode(ans[i]);
            pre_curr->right = nextnode;
            pre_curr->left = NULL;
            pre_curr = pre_curr->right;
            i++;
        }
    }
};
