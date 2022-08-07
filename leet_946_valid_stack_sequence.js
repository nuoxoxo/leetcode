/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */

var validateStackSequences = function(pushed, popped) {
    let len = popped.length
    let d = []
    let i = 0
    for (let p of pushed){
        d.unshift(p)
        while (d.length != 0 && i < len && d[0] == popped[i]){
            d.shift()
            ++i
        }
    }
    return i == len
};
