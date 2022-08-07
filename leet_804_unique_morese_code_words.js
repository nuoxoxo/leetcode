/**
 * @param {string[]} words
 * @return {number}
 */

var uniqueMorseRepresentations = function(words) {
    let E = new Set()
    for (let s of words) {
        E.add(mc(s))
    }
    return E.size
};

var mc = function(word) {
    let morse = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]
    let i = -1
    let s = ""
    while (++i < word.length) {
        s += morse[ word.charCodeAt(i) - 'a'.charCodeAt(0) ]
    }
    return s
}
