var mergeAlternately = function(word1, word2) {
    let res = ""
    i = -1
    while (++i < word1.length && i < word2.length){
        res += word1[i]
        res += word2[i]
    }
    return res + word1.slice(i) + word2.slice(i)
};
