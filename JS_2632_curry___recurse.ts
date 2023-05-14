function curry(fn: Function): Function {
    return function curried(...args) {
        if (fn.length == args.length)
            return fn(...args)
        return function (...added) {
            return curried(...args, ...added)
        }
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */

