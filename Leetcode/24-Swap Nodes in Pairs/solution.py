import typing as Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    cur = head
        
    while cur and cur.next:
        cur.val, cur.next.val = cur.next.val, cur.val
        cur = cur.next.next
            
    return head

def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if head and head.next:
        p = head.next
        head.next = swapPairs(p.next)
        p.next = head
        return p
    return head