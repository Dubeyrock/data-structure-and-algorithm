105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

9368

258

Add to List

Share
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
  
  
  
  /* code c++*/
  
  class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inToIndex[inorder[i]] = i;

    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1, inToIndex);
  }

 private:
  TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                  const vector<int>& inorder, int inStart, int inEnd,
                  const unordered_map<int, int>& inToIndex) {
    if (preStart > preEnd)
      return nullptr;

    const int rootVal = preorder[preStart];
    const int rootInIndex = inToIndex.at(rootVal);
    const int leftSize = rootInIndex - inStart;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
                       inStart, rootInIndex - 1, inToIndex);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
                        rootInIndex + 1, inEnd, inToIndex);
    return root;
  }
};

  
  
