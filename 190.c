// 190. Reverse Bits

uint32_t reverseBits(uint32_t n) {
    n = (n & 0xffff0000) >> 16 | (n & 0x0000ffff) << 16;
    n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
    n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
    n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;  // c=1100 3=0011
    n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;  // a=1010 5=0101
    return n;
}
