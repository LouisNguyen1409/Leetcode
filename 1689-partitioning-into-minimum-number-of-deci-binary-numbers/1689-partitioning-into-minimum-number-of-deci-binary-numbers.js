/**
 * @param {string} n
 * @return {number}
 */
/**
n.split('') will seperate each digit from n into an array
...n will spread the array setting it up for the next method
Math.max() will return the largest number within the array giving us our answer
*/

var minPartitions = (n) => Math.max(...n.split(''))