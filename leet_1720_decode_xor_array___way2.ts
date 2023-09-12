function decode(encoded: number[], first: number): number[] {
    const res: number[] = [first];
    let i = -1
    while (++i < encoded.length) {
        res.push(encoded[i] ^ res[res.length - 1]);
    }
    return res;
};
