/**
 * @param {number[]} asteroids
 * @return {number[]}
 */
var asteroidCollision = function(asteroids) {
    let length = asteroids.length;
    for (let i = 0; i < length - 1; i++) {
        if (asteroids[i] > 0 && asteroids[i + 1] < 0) {
            if (asteroids[i] === Math.abs(asteroids[i + 1])) {
                asteroids.splice(i, 2);
                length -= 2;
                if (i != 0) {
                    i -= 2;
                } else {
                    i--;
                }
            } else if (asteroids[i] > Math.abs(asteroids[i + 1])) {
                asteroids.splice(i + 1, 1);
                length -= 1;
                i--;
            } else {
                asteroids.splice(i, 1);
                length -= 1;
                if (i != 0) {
                    i -= 2;
                } else {
                    i--;
                }
            }
        }
    }
    return asteroids;
};