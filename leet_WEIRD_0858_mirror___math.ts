function mirrorReflection(p: number, q: number): number {
    while (p % 2 == 0 && q % 2 == 0)
    {
        p /= 2;
        q /= 2;
    }
    if (q % 2 && p % 2 == 0)
        return 2
    if (q % 2 && p % 2)
        return 1
    if (q % 2 == 0 && p % 2)
        return 0
    return -1
};
