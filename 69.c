// 69. Sqrt(x)

int mySqrt(int x) {
    int left = 0, right = x;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        long y = (long)mid * mid;
        if (y > x) {
            right = mid;
        } else if (y < x) {
            left = mid;
        } else {
            return mid;
        }
    }
    return x == 1 ? 1 : left;
}
