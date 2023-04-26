function addDigits(num: number): number {
    if (!num) {
        return num
    }
    return num % 9 ? num % 9 : 9
};
