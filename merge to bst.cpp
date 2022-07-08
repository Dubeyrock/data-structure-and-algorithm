Merge Two BSTs
Difficulty: MEDIUM
Contributed By
Prashansa
|
Level 1
Avg. time to solve
10 min
Success Rate
90%
Problem Statement
You are given two balanced binary search trees of integers having ‘N’ and ‘M’ nodes. You have to merge the two BSTs into a balanced binary search tree and return the root node to that balanced BST.
A binary search tree (BST) is a binary tree data structure with the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.


Input Format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow. 

The first line of each test case contains the elements of the first BST in the level order form separated by a single space.

If any node does not have a left or right child, take -1 in its place. Refer to the example below.

The second line of each test case contains the elements of the second BST in the level order form separated by a single space.


Example:
Elements are in the level order form. The input consists of values of nodes separated by a single space in a single line. In case a node is null, we take -1 in its place.

The input for the tree depicted in the below image would be :

Output Format :
For each test case print ‘N’ + ‘M’ space-separated integers representing the inorder traversal of the balanced binary search tree which is formed by merging both the given trees.

Output for each test case will be printed in a separate line.
Note:
You are not required to print the output, it has already been taken care of. Just implement the function.
Constraints:
1 <= T <= 50
1 <= N <= 1000
1 <= M <= 1000

Time Limit: 1 sec
Sample Input 1:
1
2 1 3 -1 -1 -1 -1
4 -1 -1
Sample Output 1:
1 2 3 4 
  
  /* code*/
  
  /*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/

void inorder(TreeNode<int> *root, vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<int> mergeArrays(vector<int> a, vector<int> b){
    vector<int> ans(a.size()+ b.size());
    
    int i = 0, j = 0;
    int k = 0;
    while(i < a.size()&& j<b.size()){
        if(a[i]<b[j]){
            ans[k++] = a[i];
            i++;
        }
        else {
            ans[k++] = b[j];
            j++;
        }
    }
    while(i<a.size()) {
        ans[k++] = a[i];
        i++;
    }
    while(j<a.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

// inorder to BST
TreeNode<int>*inorderToBST(int s, int e, vector<int> &in){
    // base case
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>*root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid-1,in);
    root->right = inorderToBST(mid+1, e , in);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // step inorder store
    
    vector<int> bst1,bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    
   vector<int> mergeArray = mergeArrays(bst1, bst2);
    
    int s = 0, e = mergeArray.size()-1;
    return inorderToBST(s, e, mergeArray);
    
}
  
