/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * function NestedInteger() {
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     @return {boolean}
 *     this.isInteger = function() {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     @return {integer}
 *     this.getInteger = function() {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds, if it holds a nested list
 *     Return null if this NestedInteger holds a single integer
 *     @return {NestedInteger[]}
 *     this.getList = function() {
 *         ...
 *     };
 * };
 */
/**
 * @constructor
 * @param {NestedInteger[]} nestedList
 */


class   NestedIterator {
    constructor(nl) {
        this.arr = []
        // function flatten(nl) {
        //  Above line does not work, why ? But arrow func works
        let flatten = nl => {
            for (let n of nl) {
                if (n.isInteger())
                    this.arr.push(n.getInteger())
                else
                    flatten(n.getList())
            }
        }
        flatten(nl)
    }
    
    next() {
        return this.arr.shift()
    }
    
    hasNext() {
        return this.arr.length != 0
    }
}


// var NestedIterator = function(nestedList) {};


/**
 * @this NestedIterator
 * @returns {boolean}
 */

// NestedIterator.prototype.hasNext = function() {};

/**
 * @this NestedIterator
 * @returns {integer}
 */

// NestedIterator.prototype.next = function() {};

/**
 * Your NestedIterator will be called like this:
 * var i = new NestedIterator(nestedList), a = [];
 * while (i.hasNext()) a.push(i.next());
*/
