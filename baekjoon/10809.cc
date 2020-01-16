#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char word[101];
    char alpha[26] = {0,};
    scanf("%s", word);
    for (int i = 0; i < strlen(word); i++)
        if (!alpha[word[i]-97])
            alpha[word[i]-97] = i+1;
    for (int i = 0; i < 26; i++)
        printf("%d ", alpha[i]-1);

    return 0;
}
