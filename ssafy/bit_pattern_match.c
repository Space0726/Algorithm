#include <stdio.h>

// To find pattern in variable a
unsigned a = 0x0DEC;
char pattern[10] = {
    0b001101,
    0b010011,
    0b111011,
    0b110001,
    0b100011,
    0b110111,
    0b001011,
    0b111101,
    0b011001,
    0b101111
};

void print_byte(char t) {
    printf("%d%d%d%d%d%d\n", (t >> 5)&1, (t >> 4)&1, (t >> 3)&1, (t >> 2)&1, (t >> 1)&1, t&1);
}

char get_next_byte(char t, int n) {
    t <<= n;
    if (n)
        t |= (a >> (10 - n)) & ((2 << n) - 1);
    t &= 0x3F;
    return t;
}

int check_pattern(char t) {
    for (int i = 0; i < 10; ++i)
        if (pattern[i] == t)
            return i;
    return -1;
}

int main() {
    char t = (a >> 10) & 0x3F;
    for (int i = 0; i <= 10; ++i) {
        int ret = check_pattern(get_next_byte(t, i));
        if (ret != -1) {
            // Print matched pattern
            printf("p: %d\n", ret);
            i += 5;
        }
    }

    return 0;
}
