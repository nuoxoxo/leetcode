/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

var compareVersion = function(version1, version2){
    let len1 = version1.length
    let len2 = version2.length
    let res1, res2, o, i, j
    res1 = res2 = i = j = 0
    o = "0".charCodeAt(0)
    while (i < len1 || j < len2){
        while (i < len1 && version1[i] !== '.'){
            res1 += version1.charCodeAt(i) -o + res1 * 10
            i++
        }
        while (j < len2 && version2[j] !== '.'){
            res2 += version2.charCodeAt(j) -o + res2 * 10
            j++
        }
        if (res1 < res2)    return -1
        if (res1 > res2)    return 1
        res1 = res2 = 0
        i++
        j++
    }
    return 0
};
