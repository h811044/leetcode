// 66. Plus One

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    for(int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            carry = 0;
            break;
        }
    }

    *returnSize = digitsSize + carry;
    int *returnDigits = (int *)malloc(sizeof(int) * (*returnSize));

    if (carry) {
        returnDigits[0] = 1;
        for (int i = 1; i < *returnSize; i++) {
            returnDigits[i] = 0;
        }
    } else {
        int i = digitsSize - 1;
        while (digits[i] == 9) {
            returnDigits[i] = 0;
            i--;
        }
        returnDigits[i] = digits[i] + 1;
        i--;
        while (i >= 0) {
            returnDigits[i] = digits[i];
            i--;
        }
    }

    return returnDigits;
}
