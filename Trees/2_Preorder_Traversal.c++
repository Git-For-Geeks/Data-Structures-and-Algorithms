class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root==NULL)return ans;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()){
            TreeNode* top_ele= stk.top();
            stk.pop();
            ans.push_back(top_ele->val);
            if(top_ele->right)stk.push(top_ele->right);
            if(top_ele->left)stk.push(top_ele->left);    
        }
        return ans;
    }
};