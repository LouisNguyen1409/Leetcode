function maximumWealth(accounts: number[][]): number {
    let max = 0;
    const length = accounts.length;
    for (let i = 0; i < length; i++) {
        let sum = accounts[i].reduce((sumItem, a) => sumItem + a, 0);
        if (sum > max) {
            max = sum;
        }
    }
    return max;
};