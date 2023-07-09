function checkIfPangram(sentence: string): boolean {
    return  [...new Set(sentence)].length == 26
};
