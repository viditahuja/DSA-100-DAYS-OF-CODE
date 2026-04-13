#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    for (int i = 0; s[i]; i++) {
        int idx = s[i] - 'a';

        if (freq[idx] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        freq[idx]++;
    }

    printf("-1");
    return 0;
}