// 405. Convert a Number to Hexadecimal

char* toHex(int num) {
    char *buffer = (char *)malloc(sizeof(char) * 9);
    int i;
    for (i = 7; i >= 0; i--) {
        int digit = num & 15;
        buffer[i] = digit > 9 ? 'a' + (digit - 10) : '0' + digit;
        num >>= 4;
    }
    for (i = 0; i < 7; i++) {
        if (buffer[i] != '0') {
            break;
        }
    }
    int j = 0;
    while (i < 8) {
        buffer[j++] = buffer[i++];
    }
    buffer[j] = '\0';
    return buffer;
}
