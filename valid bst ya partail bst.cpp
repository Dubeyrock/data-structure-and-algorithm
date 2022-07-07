Problem Statement
Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
A binary search tree (BST) is said to be a Partial BST if it follows the following properties.
• The left subtree of a node contains only nodes with data less than and equal to the node’s data.
• The right subtree of a node contains only nodes with data greater than and equal to the node’s data.
• Both the left and right subtrees must also be partial binary search trees.
  
  
  Output Format :
For each test case, return true if the binary tree is a Partial BST, else return false.

Output for every test case will be denoted in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.
Constraint :
1 <= T <= 100
1 <= N <= 1000
-10^9 <= data <= 10^9
where N is the number of nodes in the tree, T represents the number of test cases, and data denotes data contained in the node of the binary tree.

Duplicate elements can be in the right subtree or left subtree.

Time Limit: 1 sec
Sample Input 1:
2
3 1 5 -1 2 -1 -1 -1 -1
3 2 5 1 4 -1 -1 -1 -1 -1 -1
Sample Output 1:
 true
 false
   
   
   
   /*code */
   
   /*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isBST(BinaryTreeNode<int> *root,int min, int max){
    // base case
    if( root == NULL)
        return true;
    
        if (root->data >= min && root->data <=max){
            bool left = isBST(root->left,min,root->data);
            bool right = isBST(root->right,root->data, max);
                return left && right;
        }
    else
        return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,INT_MIN,INT_MAX);
}
   
