# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def traverse(self, node: TreeNode, depth: int) -> list:
        if not node:
            return []
        if node.left or node.right:
            res = []
            if node.left:
                res.extend(self.traverse(node.left, depth + 1))
            else:
                res.append(None)
            res.append((node.val, depth))
            if node.right:
                res.extend(self.traverse(node.right, depth + 1))
            else:
                res.append(None)
            return res
        else:
            return [(node.val, depth)]

    def isSymmetric(self, root: TreeNode) -> bool:
        # lst = self.traverse(root, 0)
        # print(lst)
        # return lst == lst[::-1]

        def isSym(L, R):
            if L and R and L.val == R.val:
                return isSym(L.left, R.right) and isSym(L.right, R.left)
            return L == R

        return not root or isSym(root.left, root.right)
