/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let result = ListNode(0)
        var current = result
        var carry = 0
        var m = l1
        var n = l2
        
        while m != nil || n != nil {
            var sum = carry
            if m != nil {
                sum += m!.val
                m = m!.next
            }
            if n != nil {
                sum += n!.val
                n = n!.next
            }
            
            carry = sum / 10;
            current.next = ListNode(sum % 10)
            current = current.next!
        }
        
        if carry > 0 {
            current.next = ListNode(carry)
        }
        
        return result.next
    }
}
