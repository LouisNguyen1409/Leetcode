/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let isNeg = false;
    if (x < 0) {
        isNeg = true;
    }
    let arr = x.toString().split("").reverse().join("");
    if (isNeg) {
        arr = -parseInt(arr);
    } else {
        arr = parseInt(arr);
    }
    if (Math.pow(-2,31) <= arr && arr <= (Math.pow(2,31) - 1)) {
        return arr;
    }

    return 0;
    
};