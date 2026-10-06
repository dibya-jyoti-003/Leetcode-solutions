# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode | None) -> ListNode | None:
        if not head:
            return head
        sp = head
        fp = head
        while True:
            fp = fp.next
            if not fp:
                break
            sp = sp.next
            fp = fp.next
            if not fp:
                break
        return sp