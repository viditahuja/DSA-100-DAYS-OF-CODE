#include <stdio.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0, j = 0;

    while (s[j] != '\0')
        j++;
    j--;

    while (i < j) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}