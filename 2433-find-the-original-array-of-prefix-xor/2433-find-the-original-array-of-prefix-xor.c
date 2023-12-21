/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize) {
    *returnSize = prefSize;
    int* final = malloc(sizeof(int) * prefSize);
    final[0] = pref[0];
    int temp = final[0];
    for (int i = 1; i < prefSize; i++) {
        if (i != 1) {
            temp ^= final[i - 1];
        }
        final[i] = temp ^ pref[i];
    }
    return final;
}