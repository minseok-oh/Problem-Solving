import collections
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def maxDepth(self, root: Optional[TreeNode]) -> int:
    if root is None:
        return 0
        
    queue = collections.deque([root])
    depth = 0
        
    while queue:
        depth += 1
            
        for _ in range(len(queue)):
            cur_node = queue.popleft()
            if cur_node.left:
                queue.append(cur_node.left)
            if cur_node.right:
                queue.append(cur_node.right)
    return depth