type F = (x: number) => number;

function compose(functions: F[]): F {
	return function(x) {
        let i = functions.length
        while (--i > -1) {
            x = functions[i](x)
        }
        return x
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
