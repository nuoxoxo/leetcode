/**
 * @param {number} buckets
 * @param {number} minutesToDie
 * @param {number} minutesToTest
 * @return {number}
 */
var poorPigs = function(buckets, mtd, mtt) {
    let pigs = 0
    while (Math.pow(Math.floor(mtt / mtd + 1), pigs) < buckets)
        ++pigs;
    return pigs
};
