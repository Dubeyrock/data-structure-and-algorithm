# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right




## Approach 1: Recursion
## Intuition
## The problem gives a binary tree and requires returning the lowest common ancestor of its deepest leaf node. The depth of the tree's root node is 0. We note that all nodes with the maximum depth are leaf nodes. For convenience, we refer to the lowest common ancestor of the deepest leaf nodes as the lca node.

## We use a recursive method to perform a depth-first search, recursively traversing each node in the tree and returning the maximum depth d of the current subtree and the lca node. If the current node is null, we return depth 0 and an null node. In each search, we recursively search the left and right subtrees, and then compare the depths of the left and right subtrees:

## If the left subtree is deeper, the deepest leaf node is in the left subtree, we return {left subtree depth + 1, the lca node of the left subtree}
## If the right subtree is deeper, the deepest leaf node is in the right subtree, we return {right subtree depth + 1, the lca node of the right subtree}
## If both left and right subtrees have the same depth and both have the deepest leaf nodes, we return {left subtree depth + 1, current node}.



class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(node):
            if not node: return (0, None) # (depth, lca)
            l, l_lca = dfs(node.left)
            r, r_lca = dfs(node.right)
            if l == r: return (l + 1, node)
            return (l + 1, l_lca) if l > r else (r + 1, r_lca)
        return dfs(root)[1]



### 2nd method 

class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if not root:
                return 0, None

            left = dfs(root.left)
            right = dfs(root.right)

            if left[0] > right[0]:
                return left[0] + 1, left[1]
            if left[0] < right[0]:
                return right[0] + 1, right[1]
            return left[0] + 1, root

        return dfs(root)[1]
