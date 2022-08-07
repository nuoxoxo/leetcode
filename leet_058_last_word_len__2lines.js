/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let a = s.split(' ').filter((x) => x != '')
    return a[a.length - 1].length
};
