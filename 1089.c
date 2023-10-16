// 1089. Duplicate Zeros

void duplicateZeros(int* arr, int arrSize){
    int i = 0, j = 0;

    while (j < arrSize) {
        if (arr[i] == 0) {
            j++;
        }
        i++;
        j++;
    }
    i--;
    j--;

    if (j == arrSize) {
        j--;
        arr[j--] = arr[i--];
    }
    while (i >= 0) {
        if (arr[i] == 0) {
            arr[j--] = arr[i];
        }
        arr[j--] = arr[i--];
    }
}
