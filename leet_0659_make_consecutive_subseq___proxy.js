/**
 * @param {number[]} nums
 * @return {boolean}
 */

class DefaultDict {
  constructor(defaultVal) {
    return new Proxy({}, {
      get: (target, name) => name in target ? target[name] : defaultVal
    })
  }
}

// const counts = new DefaultDict(0)

var isPossible = function(nums) {
    let freq = new DefaultDict(0)
    let subs = new DefaultDict(0)
    for (let n of nums) {
        freq[n] += 1
    }
    // console.log(freq)
    for (let n of nums) {
        if (freq[n] == 0)
            continue
        freq[n] -= 1
        if (subs[n - 1] > 0) {
            subs[n - 1] -= 1
            subs[n] += 1
        } else if (freq[n + 1] > 0 && freq[n + 2] > 0) {
            freq[n + 1] -= 1
            freq[n + 2] -= 1
            subs[n + 2] += 1
        } else {
            return false
        }
    }
    return true
};
