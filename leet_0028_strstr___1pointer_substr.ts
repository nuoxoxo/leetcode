function strStr(haystack: string, needle: string): number {
    let len_hays = haystack.length
    let len_need = needle.length
    if (len_need == 0)
        return 0
    if ((len_hays == 0) || len_hays < len_need)
        return -1
    let i = -1
    let end = len_hays - len_need + 1
    while (++i < end) {
        if (haystack.substr(i, len_need) == needle)
            return i
    }
    return -1
};
