var average = function(s) {
    return (s.reduce((a, b) => a + b, 0) - Math.max(...s) - Math.min(...s)) / (s.length - 2)
};
