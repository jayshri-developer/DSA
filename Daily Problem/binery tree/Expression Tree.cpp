// Approach 1
//GFG link: https://practice.geeksforgeeks.org/problems/expression-tree/1
// TC: O(n)

class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root) {
        // Your code here
        if(root == NULL)
        {
            return 0;
        }
        
        int left = evalTree(root->left);
        int right = evalTree(root->right);
        
        if(root->data == "*")
        {
            return left * right;
        }
        else if(root->data == "+")
        {
            return left + right;
        }
        else if(root->data == "/")
        {
            return left / right;
        }
        else if(root->data == "-")
        {
            return left - right;
        }
        else
        {
            return stoi(root->data);
        }
    }
};
