function* fibGenerator(): Generator<number, any, number> {
    let [l, r] = [0, 1]
    yield l
    yield r
    while (true) {
        let sum = l + r
        l = r
        r = sum
        yield sum
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */
