function decode(encoded: number[], first: number): number[] {
    const res: number[] = [first];
    for (const n of encoded) {
      first ^= n;
      res.push(first);
    }
    return res;
};
