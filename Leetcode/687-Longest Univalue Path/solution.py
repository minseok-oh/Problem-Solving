from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    
res: int = 0
def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
    def dfs(node: TreeNode) -> int:
        if node is None:
            return 0
            
        left = dfs(node.left)
        right = dfs(node.right)
            
        if node.left and node.val == node.left.val:
            left += 1
        else:
            left = 0
        if node.right and node.val == node.right.val:
            right += 1
        else:
            right = 0
                
        self.res = max(self.res, left + right)
        return max(left, right)
    
    dfs(root)
    return self.res