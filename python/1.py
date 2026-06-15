# class ListNode:
#      def __init__(self, val=0, next=None):
#          self.val = val
#          self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        count=0
        dummy=ListNode()
        l3=dummy 
        while l1!=None or l2!=None or count!=0:
            value=0
            value+=count
            if l1!=None:
                value+=l1
                l1=l1.next
            if l2!=None:
                value+=l2
                l2=l2.next
            count=value//10
            value%=10
            temp=ListNode(value)
            l3.next=temp
            l3=l3.next
        return dummy.next