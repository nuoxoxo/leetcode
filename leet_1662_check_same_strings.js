/**
 * @param {string[]} word1
 * @param {string[]} word2
 * @return {boolean}
 */



var arrayStringsAreEqual = function(word1, word2) {
    let  s1 = "", s2 = "";
    for (let w of word1)
        s1 += w;
    for (let w of word2)
        s2 += w;
    return (s1 === s2);
};
