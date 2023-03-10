/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 */
var Solution = function(head) {
    this.ptr = head
};

/**
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    let p = this.ptr
    let a = []
    while (p) {
        a.push(p.val)
        p = p.next
    }
    return a[parseInt(Math.random() * a.length)]
};

/** 
 * Your Solution object will be instantiated and called as such:
 * var obj = new Solution(head)
 * var param_1 = obj.getRandom()
 */
