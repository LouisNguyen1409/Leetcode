/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* final = calloc(pricesSize, sizeof(int));
    for (int i = 0; i < pricesSize; i++) {
        int j = i + 1;
        while (j < pricesSize && prices[j] > prices[i]) {
            j += 1;
        }
        if (j < pricesSize) {
            final[i] = prices[i] - prices[j];
        } else {
            final[i] = prices[i];
        }

    }
    return final;
}