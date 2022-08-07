var getDecimalValue = function(head) {
    let binstr = ""
    let p = head
    while (p != undefined){
        binstr += String.fromCharCode(p.val + "0".charCodeAt(0))
        p = p.next
    }
    return parseInt(binstr, 2)
};
