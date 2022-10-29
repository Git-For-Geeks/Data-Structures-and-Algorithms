//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    private:
        //function to calculate inorder traversal
        void inorder(Node* root, vector<int >& vector){
            if(root == NULL) return;

            //recursively calling inorder function for left node
            inorder(root->left, vector);
            vector.push_back(root->data);
            
            //recursively calling inorder function for right node
            inorder(root->right, vector);
        }
        
        
        vector<int > merge(vector<int> vec1, vector<int> vec2){
            
            vector<int> final;
            int i = 0, j = 0;
            int size1 = vec1.size();
            int size2 = vec2.size();
            
            while(i < size1 && j < size2){
                int value1 = vec1[i];
                int value2 = vec2[j];
                
                //storing the minimum element first
                //if both are same, then storing both
                if(value1 < value2){
                    final.push_back(value1);
                    i++;
                }else if(value2 < value1){
                    final.push_back(value2);
                    j++;
                }else{
                    final.push_back(value1);
                    final.push_back(value2);
                    i++;
                    j++;
                }
            }
            while(i < size1){
                 final.push_back(vec1[i++]);
            }
             while(j < size2){
                 final.push_back(vec2[j++]);
            }
            return final;
        }
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> vector1;
       vector<int> vector2;
       
       //calculating inorder traversal for both the tree
       //and storing it in vector1 and vector2
       inorder(root1, vector1);
       inorder(root2, vector2);
       
       return  merge(vector1, vector2);
       
    }
};


//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends