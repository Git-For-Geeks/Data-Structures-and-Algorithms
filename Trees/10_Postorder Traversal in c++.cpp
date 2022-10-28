class Solution {
  public:
  
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        if(root == NULL)return ans;
        
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
        return ans;
        
    }
};