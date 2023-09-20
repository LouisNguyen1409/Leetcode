function fizzBuzz(n: number): string[] {
    let ans = []
    for (let num = 1; num <= n; num++) {
        if (num % 3 === 0 && num % 5 === 0) {
            ans[num - 1] = "FizzBuzz";
        } else if (num % 3 === 0) {
            ans[num - 1] = "Fizz";
        } else if (num % 5 == 0) {
            ans[num - 1] = "Buzz";
        } else {
            ans[num - 1] = num.toString();
        }
    }
    return ans;
};