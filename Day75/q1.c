#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    int hash[200001];
    for (int i = 0; i < 200001; i++)
        hash[i] = -1;

    int offset = 100000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        if (hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}