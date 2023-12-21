// 371. Sum of Two Integers

int getSum(int a, int b) {
    unsigned int ua = (unsigned int)a;
    unsigned int ub = (unsigned int)b;
    unsigned int answer = ua ^ ub;
    unsigned int carry = (ua & ub) << 1;
    while (carry) {
        unsigned int temp = answer ^ carry;
        carry = (answer & carry) << 1;
        answer = temp;
    }
    return (int)answer;
}
