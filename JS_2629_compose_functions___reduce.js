/**
 * @param {Function[]} functions
 * @return {Function}
 */

var compose = function(functions) {
    return function(x) {
        let init = x
        let res = x
        functions.reverse()
        return functions.reduce(
            (res, fn, index) => res = fn(res), // callbackFn
            init //initialValue
        )
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
