Problem Statement
Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).
BST ( binary search tree) -
If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.


Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }
Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.
Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

 
  /**  Following is the Binary Tree node structure

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

int solve(BinaryTreeNode<int>* root, int& i, int k){
    // base case
    if(root == NULL){
        return -1;
    }
    // l
    int left = solve(root->left, i, k);
    
    if(left!=-1){
        return left;
    }
    // n
    i++;
    if(i==k)
     return root->data;
    
    // r
    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i =0;
    int ans = solve(root, i, k);
    return ans;
}
