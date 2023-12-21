/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function(operations) {
    let final = 0;
    for (const operation of operations) {
        if (operation === "++X" || operation === "X++") {
            final += 1;
        } else {
            final -= 1;
        }
    }
    return final;
};