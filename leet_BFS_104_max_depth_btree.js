/// BFS

var maxDepth = function(root) {
    if (!root)  return (0)
    let E = [ root ]
    let depth = 0
    while (E.length != 0) {
        let i = -1, len = E.length
        while (++i < len) {
            let node = E.shift()
            if (node.left)  E.push(node.left)
            if (node.right) E.push(node.right)
        }
        ++ depth
    }
    return (depth)
};
