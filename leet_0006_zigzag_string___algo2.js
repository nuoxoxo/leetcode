/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

var convert = function(s, numRows) {
    if (numRows < 2)
        return s;
    let n = s.length;
    let i = -1;
    let res = ''
    while (++i < numRows)
    {
        let r = 2 * (numRows - 1);
        let c = i;
        while (c < n)
        {
            res += s[c];
            let in_between = r + c - i * 2;
            if (i < numRows - 1 && i > 0 && in_between < n)
                res += s[in_between];
            c += r;
        }
    }
    return res;
};
