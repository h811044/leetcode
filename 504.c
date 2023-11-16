// 504. Base 7

char* convertToBase7(int num) {
    char *buffer = (char *)malloc(sizeof(char) * 16);
    int num7 = 0;
    int order = 1;
    while (num) {
        num7 += (num % 7) * order;
        num /= 7;
        order *= 10;
    }
    sprintf(buffer, "%d", num7);
    return buffer;
}
