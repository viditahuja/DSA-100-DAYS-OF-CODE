#include <stdio.h>

int main() {
    char s[100];
    scanf("%s", s);

    int i = 0, j = 0;
    while (s[j] != '\0')
        j++;
    j--;

    while (i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }

    printf("%s", s);
    return 0;
}