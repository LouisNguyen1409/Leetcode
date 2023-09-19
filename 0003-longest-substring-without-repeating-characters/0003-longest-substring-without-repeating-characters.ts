function lengthOfLongestSubstring(s: string): number {
    if (!s) {
        return 0;
    }
    const max = new Set([1])
    let newS = '';
    for(const letter of s) {
        if(!newS.includes(letter)) {
            newS += letter
            
            max.add(newS.length)
        } else {
            newS = newS.slice(newS.indexOf(letter) + 1).concat(letter)
        }
    }
    return Math.max(...(max));
}