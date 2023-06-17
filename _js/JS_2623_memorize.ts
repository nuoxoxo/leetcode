type Fn = (...params: any) => any

function memoize(fn: Fn): Fn {
    let dict = new Object()
    return function(...args) {
        let key = args.join()
        if ( ! dict.hasOwnProperty(key)) {
            dict[key] = fn(...args)
        }
        return dict[key]
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
