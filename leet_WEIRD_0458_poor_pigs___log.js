/**
 * @param {number} buckets
 * @param {number} minutesToDie
 * @param {number} minutesToTest
 * @return {number}
 */
var poorPigs = function(buckets, mtd, mtt) {
    return Math.ceil(Math.log(buckets) / Math.log(mtt / mtd + 1))
};
