function decode(encoded: number[], first: number): number[] {
    const res: number[] = [first];
    for (let i = 0; i < encoded.length; i++) {
        res.push(encoded[i] ^ res[res.length - 1]);
    }
    return res;
};
