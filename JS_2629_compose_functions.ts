type F = (x: number) => number;

// way 2: reduce

function compose(functions: F[]): F {
    return function(x) {
        let init: number = x
        let res: number = x
        functions.reverse()
        return functions.reduce(
            (res, fn, index) => res = fn(res), // callbackFn
            init //initialValue
        )
    }
};

// way 1: iterative

/*
function compose(functions: F[]): F {
    return function(x) {
        let i = functions.length
        while (--i > -1) {
            x = functions[i](x)
        }
        return x
    }
};
*/

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */

