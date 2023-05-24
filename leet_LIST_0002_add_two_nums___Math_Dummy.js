var addTwoNumbers = function(t1, t2) {
    let head = new ListNode()
    let curr = head
    let carry = 0
    while (t1 != undefined || t2 != undefined || carry != 0) {
        if (t1) {
            carry += t1.val
            t1 = t1.next
        }
        if (t2) {
            carry += t2.val
            t2 = t2.next
        }
        let temp = new ListNode(carry % 10)
        curr.next = temp
        curr = curr.next
        carry = Math.floor(carry / 10)
    }
    head = head.next
    return head
};
