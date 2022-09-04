import collections
from typing import Deque, List, Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def isPalindrome(self, head: Optional[ListNode]) -> bool:
    q: List = []
            
    if not head:
        return True
        
    node = head
    while node is not None:
        q.append(node.val)
        node = node.next
        
    while len(q) > 1:
        if q.pop() != q.pop(0):
            return False
            
    return True

def isPalindrome(self, head: Optional[ListNode]) -> bool:
    dq: Deque = collections.deque()
        
    if not head:
        return True
        
    node = head
    while node is not None:
        dq.append(node.val)
        node = node.next
            
    while len(dq) > 1:
        if dq.popleft() != dq.pop():
            return False
            
    return True