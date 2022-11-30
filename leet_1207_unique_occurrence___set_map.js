/**
 * @param {number[]} arr
 * @return {boolean}
 */

var uniqueOccurrences = function(arr) {
    const map = new Map()
    const set = new Set()

    arr.forEach(num => {
        let temp = map.get(num) || 0
        map.set(num, temp + 1)
    })

    for (let n of map.values()) {
        if (set.has(n)) {
            return false
        }
        else {
            set.add(n)
        }
    }

    return true
};
