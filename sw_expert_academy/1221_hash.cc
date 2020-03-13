#include <cstdio>

#define MAX_LEN 4
#define MAX_TABLE 200

using namespace std;

struct Hash {
    char key[MAX_LEN];
    int data;
};
Hash tb[MAX_TABLE];

int cnt[MAX_TABLE];
char table[10][4] = {
    "ZRO",
    "ONE",
    "TWO",
    "THR",
    "FOR",
    "FIV",
    "SIX",
    "SVN",
    "EGT",
    "NIN",
};

bool strcmp(char *str1, char *str2) {
    for (; *str1; ++str1)
        if (*str1 != *str2++)
            return false;
    return true;
}

void strcpy(char *from, char *to) {
    for (; *from; ++from)
        *to++ = *from;
    *from = '\0';
}

unsigned long hash(char *str) {
    unsigned long hash_val = 5381;
    int c;
    while (c == *str++)
        hash_val = (((hash_val << 5) + hash_val) + c) % MAX_TABLE;
    return hash_val % MAX_TABLE;
}

int find(char *key) {
    unsigned long h = hash(key);
    int cnt = MAX_TABLE;
    while (tb[h].key[0] && cnt--) {
        if (strcmp(tb[h].key, key))
            return tb[h].data;
        h = (h + 1) % MAX_TABLE;
    }
    return tb[h].data;
}

void add(char *key, int data) {
    unsigned long h = hash(key);
    while (tb[h].key[0]) {
        if (strcmp(tb[h].key, key))
            return;
        h = (h + 1) % MAX_TABLE;
    }
    strcpy(key, tb[h].key);
    tb[h].data = data;
}

void init() {
    for (int i = 0; i < 10; ++i)
        add(table[i], i);
}

int main() {
    int T, N;
    char test_case[MAX_LEN], tmp[MAX_LEN];
    scanf("%d", &T);
    init();
    while (T--) {
        T = 1;
        scanf("%s%d", test_case, &N);
        for (int i = 0; i < N; ++i) {
            scanf("%s", tmp);
            ++cnt[find(tmp)];
        }
        printf("%s\n", test_case);
        for (int i = 0; i < 10; ++i)
            while (cnt[i]--)
                printf("%s ", table[i]);
        putchar('\n');
    }
    return 0;
}
