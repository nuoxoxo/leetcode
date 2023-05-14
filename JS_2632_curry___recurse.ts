function curry(fn: Function): Function {
    
    // recursive straightforward currying

    return function curried(...args) {
        if (fn.length == args.length)
            return fn(...args)
        return function (...added) {
            return curried(...args, ...added)
        }
        // using arrow be like
        // return (...added) => curried(...args, ...added)
    };

    // recursive with caching

    let cache = []
    return function curried(...args) {
        cache = [...cache, ...args]
        if (cache.length == fn.length)
            return fn(...cache)
        return curried
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);
 * csum(1)(2) // 3
 */


