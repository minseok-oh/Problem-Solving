import typing as Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None:
        return None
        
    odd = head
    even = head.next
    even_head = head.next
        
    while even and even.next:
        odd.next, even.next = odd.next.next, even.next.next
        odd, even = odd.next, even.next
            
    odd.next = even_head
    return head