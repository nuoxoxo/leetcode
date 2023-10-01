/**
 * @param {string} s
 * @return {string}
 */

var reverseWords = function(s) {
    temp = s.split(' ').filter(w => w != '')
    temp.forEach((w, i) => {
        temp[i] = w.split('').reverse().join('')
    })
    return temp.join(' ')
};
