/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> v;

    void nodeLevel(Node *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (level == 0)
        {
            v.push_back(root->data);
        }
        else
        {
            nodeLevel(root->left, level - 1);
            nodeLevel(root->right, level - 1);
        }
    }
    int height(Node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
            return rightHeight + 1;
    }

    vector<int> levelOrder(Node *node)
    {
        int level = 0;
        int H = height(node);
        while (level <= H)
        {
            nodeLevel(node, level);
            level++;
        }
        return v;
    }
};